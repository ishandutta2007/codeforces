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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int ans=1e9,n,c[222],k[222],kk[222],f[222],d,aa,ss,x;
vector<int>v[222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> c[i],c[i]--;
	for (int i=0;i<n;i++){
		cin >> k[i];
		for (int j=0;j<k[i];j++){
			cin >> x;
			v[x-1].pb(i);
		}
	}
	for (int s=0;s<3;s++){
		for (int i=0;i<n;i++)kk[i]=k[i];
		aa=n;
		ss=s;
		m0(f);
		d=0;
		for(;;){
			for(;;){
				int t=0;
				for (int i=0;i<n;i++)if (c[i]==ss&&!f[i]&&!kk[i]){
					t=1;
					d++;
					f[i]=1;
					for (int j=0;j<v[i].size();j++)kk[v[i][j]]--;
				}
				if (!t)break;
			}
			if (d==n)break;
			aa++;
			ss=(ss+1)%3;
		}
		ans=min(ans,aa);
	}
	CC(ans);
	return 0;
}