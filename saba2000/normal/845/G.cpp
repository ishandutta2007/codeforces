
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int P[100009], C[100009];
bool F[100009];
vector<pair<int,int> > v[100009];
vector<int> cyc;
void dfs (int x, int D){
C[x]=D;
	F[x]=1;
	for (int i=0; i<v[x].size(); i++){
		int N=v[x][i].fi, W=v[x][i].se;
		if (F[N])
			cyc.push_back(P[x]^ P[N]^W);
		else{
			P[N]=(P[x] ^ W);
			dfs(N, D);
		}}}
int main()
{
int n,m;
cin>>n>>m;
	for (int i=0; i<m; i++){
            int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
			dfs(1, 0);
			int r=0;
			for (int b=30; b>=0; b--){
				int x;
				for (x=r; x<cyc.size(); x++)
					if ( (cyc[x]>> b)&1 )
						break;
				if (x == cyc.size()) continue;
				swap(cyc[r], cyc[x]);
				for (int j=r+1; j<cyc.size(); j++)
					if ( (cyc[j]>>b)&1 )
						cyc[j] ^= cyc[r];
				r++;
			}
		int ret=(P[1] ^ P[n]);
		for (int i=0; i<cyc.size(); i++)
			ret=min(ret, ret ^ cyc[i]);
		printf("%d\n", ret);
	return 0;
}