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

int n,m,x,y,q[111],o;
long long a,b,f[111];
vector<int>v[111];
vector<long long>k[111],kk[111];

void rec(int x){
	q[x]=1;
	for (int i=0;i<v[x].size();i++){
		if (f[v[x][i]]){
			if (kk[x][i]!=__gcd(f[x],f[v[x][i]]))o=1;
			if (k[x][i]!=f[x]*f[v[x][i]]/__gcd(f[x],f[v[x][i]]))o=1;
		}else{
			if (k[x][i]*kk[x][i]%f[x]){
				o=1;
				return;
			}
			f[v[x][i]]=k[x][i]*kk[x][i]/f[x];
			rec(v[x][i]);
		}
	}
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> x >> y >> a >> b;
		x--;
		y--;
		v[x].pb(y);
		k[x].pb(b);
		kk[x].pb(a);
		v[y].pb(x);
		k[y].pb(b);
		kk[y].pb(a);
	}
	for (int i=0;i<n;i++)if (!f[i]){
		if (v[i].empty()){
			f[i]=1;
			continue;
		}
		long long e=k[i][0];
		int s=sqrt(e)+1e-9;
		for (int j=1;j<=s;j++)if (e%j==0){
			m0(q);
			o=0;
			f[i]=j;
			rec(i);
			if (o){
				for (int l=0;l<n;l++)if (q[l])f[l]=0;
			}else break;

			m0(q);
			o=0;
			f[i]=e/j;
			rec(i);
			if (o){
				for (int l=0;l<n;l++)if (q[l])f[l]=0;
			}else break;
		}
	}
	for (int i=0;i<n;i++)if (!f[i]){
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i=0;i<n-1;i++)cout << f[i] << " ";
	cout << f[n-1] << endl;
	return 0;
}