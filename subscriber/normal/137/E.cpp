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

char a[211111];
int f[211111],s[1111111],ans,o,n;

int find(int x){
	int r=1e9;
	while (x){
		r=min(r,s[x]);
		x&=x-1;
	}
	return r;
}

void add(int x,int v){
	while (x<999999){
		s[x]=min(s[x],v);
		x=x+x-(x&(x-1));
	}
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	for (int i=0;i<n;i++)if (a[i]<'a')a[i]+='a'-'A';
	for (int i=0;i<n;i++)if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')a[i]=-1;else a[i]=2;
	for (int i=0;i<n;i++)f[i+1]=f[i]+a[i];
	m1(s);
	add(211111,0);
	for (int i=1;i<=n;i++){
		int x=find(f[i]+211111);
		if (i-x>ans)ans=i-x,o=0;
		if (i-x==ans)o++;
		add(f[i]+211111,i);
	}
	if (!ans)puts("No solution");else
	cout << ans << " " << o << endl;
	return 0;
}