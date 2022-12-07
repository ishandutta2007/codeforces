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

char a[333333];
int k,n,e,c[20][333333],d[333333];
pair<pt,int>p[333333];

int lcp(int x,int y){
	int r=0;
	for (int i=17;i>=0;i--)if (c[i][x]&&c[i][x]==c[i][y]){
		r+=pw(i);
		x+=pw(i);
		y+=pw(i);
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	cin >> k;
	n=strlen(a);
	for (int i=0;i<n;i++)p[i]=mp(mp(a[i],a[i]),i);
	sort(p,p+n);
	e=1;
	for (int i=0;i<n;i++){
		if (i&&p[i].F!=p[i-1].F)e++;
		c[0][p[i].S]=e;
	}
	for (int o=1;pw(o)<=n;o++){
		for (int i=0;i<n;i++)p[i]=mp(mp(c[o-1][i],c[o-1][i+pw(o-1)]),i);
		sort(p,p+n);
		e=1;
		for (int i=0;i<n;i++){
			if (i&&p[i].F!=p[i-1].F)e++;
			c[o][p[i].S]=e;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=d[i];j<n-p[i].S;j++){
			int x=i;
			for(;;){
				if (k==1){
					for (int l=p[i].S;l<p[i].S+j+1;l++)putchar(a[l]);
					puts("");
					return 0;
				}
				k--;
				x++;
				if (x==n||lcp(p[i].S,p[x].S)<j+1)break;
				d[x]=j+1;
			}
		}
	}
	puts("No such line.");
	return 0;
}