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

int n,m,ans=0,as=1e9,a1,a2;
map<string,pt >e;
char a[33][33];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++)gets(a[i]);
	for (int ii=1;ii<=n;ii++)for (int jj=1;jj<=m;jj++)if (n%ii==0&&m%jj==0){
		e.clear();
		int t=0;
		for (int i=0;i<n/ii;i++)for (int j=0;j<m/jj;j++){
			string s="";
			for (int x=0;x<ii;x++)for (int y=0;y<jj;y++)s+=a[i*ii+x][j*jj+y];
			if (e.find(s)!=e.end()&&e[s]!=mp(i+1,j))t=1;
			e[s]=mp(i+1,j);
			s="";
			for (int x=0;x<ii;x++)for (int y=0;y<jj;y++)s+=a[i*ii+ii-x-1][j*jj+jj-y-1];
			if (e.find(s)!=e.end()&&e[s]!=mp(i+1,j))t=1;
			e[s]=mp(i+1,j);
			if (ii==jj){
				s="";
				for (int x=0;x<ii;x++)for (int y=0;y<jj;y++)s+=a[i*ii+ii-y-1][j*jj+x];
				if (e.find(s)!=e.end()&&e[s]!=mp(i+1,j))t=1;
				e[s]=mp(i+1,j);
				s="";
				for (int x=0;x<ii;x++)for (int y=0;y<jj;y++)s+=a[i*ii+y][j*jj+ii-x-1];
				if (e.find(s)!=e.end()&&e[s]!=mp(i+1,j))t=1;
				e[s]=mp(i+1,j);
			}
		}
		if (!t){
			ans++;
			if (ii*jj<as||ii*jj==as&&ii<a1)as=ii*jj,a1=ii,a2=jj;
		}
	}
	cout << ans << endl << a1 << " " << a2 << endl;
	return 0;
}