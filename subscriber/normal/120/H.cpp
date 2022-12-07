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

int n,m=0,f[222],q[1111111];
vt v[222];
string s[222],w[1111111],ans[222];
map<string,int>o;

bool rec(int x){
	if (f[x])return 0;
	f[x]=1;
	for (int i=0;i<v[x].size();i++)if (q[v[x][i]]==0){
		q[v[x][i]]=x+1;
		return 1;
	}
	for (int i=0;i<v[x].size();i++)if (rec(q[v[x][i]]-1)){
		q[v[x][i]]=x+1;
		return 1;
	}
	return 0;
}


int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> s[i];
	for (int i=0;i<n;i++){	
		int k=s[i].size();
		for (int l0=0;l0<k;l0++)for (int l1=l0+1;l1<=k;l1++)
		for (int l2=min(k,l1+1);l2<=k;l2++)for (int l3=min(k,l2+1);l3<=k;l3++){
			string g="";
			g+=s[i][l0];
			if (l1<k)g+=s[i][l1];
			if (l2<k)g+=s[i][l2];
			if (l3<k)g+=s[i][l3];
			if (o.find(g)!=o.end())v[i].pb(o[g]);else{
				o[g]=m;
				w[m++]=g;
				v[i].pb(m-1);
			}
		}
	}
	for (int i=0;i<n;i++){
		m0(f);
		if (!rec(i)){
			puts("-1");
			return 0;
		}
	}
	for (int i=0;i<m;i++)if (q[i])ans[q[i]-1]=w[i];
	for (int i=0;i<n;i++)CC(ans[i]);
	return 0;
}