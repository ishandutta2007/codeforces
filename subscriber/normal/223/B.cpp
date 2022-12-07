#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

char a[222222],b[222222];
int n,m,p,u[222222],uu[222222],z[33];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	gets(b);
	n=strlen(a);
	m=strlen(b);
	for (int i=0;i<n;i++)u[i]=-1;
	p=-1;
	for (int i=0;i<m;i++){
		p++;
		while (p<n&&a[p]!=b[i])p++;
		if (p==n){
			puts("No");
			return 0;
		}
		u[p]=i;
	}
	for (int i=0;i<26;i++)z[i]=-1;
	for (int i=0;i<n;i++){
		z[a[i]-'a']=max(z[a[i]-'a'],u[i]);
		u[i]=z[a[i]-'a'];
	}
	p=n;
	for (int i=0;i<n;i++)uu[i]=1e9;
	for (int i=0;i<26;i++)z[i]=1e9;
	for (int i=m-1;i>=0;i--){
		p--;
		while (a[p]!=b[i])p--;
		uu[p]=i;
	}
	for (int i=n-1;i>=0;i--){
		z[a[i]-'a']=min(z[a[i]-'a'],uu[i]);
		uu[i]=z[a[i]-'a'];
	}
	for (int i=0;i<n;i++)if (u[i]<uu[i]){
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}