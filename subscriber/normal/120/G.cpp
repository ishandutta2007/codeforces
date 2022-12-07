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

int n,T,t,x,y,k,u=0,a[111][111],b[111][111],c[111],f[111],o,d[111][111];
string s[111];
vector<string>ans[111];

int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> n >> T;
	for (int i=0;i<n;i++)for (int j=0;j<2;j++)cin >> a[i][j] >> b[i][j];
	cin >> k;
	for (int i=0;i<k;i++)cin >> s[i] >> c[i];
	x=0;
	y=0;
	o=k;
	while(o){
		t=T;
		while (t){
			int e=max(1,c[u]-(a[x][y]+b[x][y^1])-d[x][u]);
			if (e<=t){
				t-=e;
				ans[x].pb(s[u]);
				f[u]=1;
				o--;
				if (!o)break;
				u=(u+1)%k;
				while (f[u])u=(u+1)%k;
			}else{
				d[x][u]+=t;
				t=0;
				u=(u+1)%k;
				while (f[u])u=(u+1)%k;
			}
		}
		x++;
		if (x==n){
			x=0;
			y^=1;
		}
	}
	for (int i=0;i<n;i++){
		cout << ans[i].size();
		for (int j=0;j<ans[i].size();j++)cout << " " << ans[i][j];
		puts("");
	}
	return 0;
}