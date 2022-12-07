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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int x,n,p[1111111],q1[1111111],q2[1111111];
char a[1111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	p[0]=-1;
	for (int i=1;i<n;i++){
		x=p[i-1];
		while (x!=-1&&a[x+1]!=a[i])x=p[x];
		if (a[x+1]==a[i])p[i]=x+1;else p[i]=-1;
	}
	for (int i=1;i<n-1;i++)if (p[i]>=0)q1[p[i]]=1;
	if (p[n-1]>=0)q2[p[n-1]]=2;
	for (int i=n-1;i>=0;i--)if (p[i]>=0){
		q1[p[i]]|=q1[i];
		q2[p[i]]|=q2[i];		
	}
	for (int i=n-1;i>=0;i--)if (q1[i]&&q2[i]){
		for (int j=0;j<=i;j++)putchar(a[j]);
		return 0;
	}
	puts("Just a legend");
	return 0;
}