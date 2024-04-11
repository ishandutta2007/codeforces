#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N = 1010;
string matr[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	for(int i=0;i<n;++i)
		cin >> matr[i];
	vector<pair<int,int>>q;
	vector<vector<int>>dist(n, vector<int>(m, -1));
	vector<int>dx={0,1,0,-1};
	vector<int>dy={1,0,-1,0};
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){ 
			bool ok=false;
			for(int k=0;k<4;++k){
				 int x=i+dx[k];
				 int y=j+dy[k];
				 if(x >=0&&y>=0&&x<n&&y<m&&matr[x][y]==matr[i][j])
					 ok=true;
			}
			if (ok)
				dist[i][j] = 0, q.emplace_back(i,j);
		}
	for(int t=0;t<q.size();++t){
		int i=q[t].first,j=q[t].second;
		for(int k=0;k<4;++k){
			int x=i+dx[k];
			int y=j+dy[k];
			if(x >=0&&y>=0&&x<n&&y<m&&dist[x][y]==-1)
				dist[x][y]=dist[i][j]+1,q.emplace_back(x,y);
		}
	}
	while(t--) {
		int i, j;
		nagai p;
		cin >> i >> j >> p;
		--i,--j;
		if (p == 0) {
			cout << matr[i][j] << '\n';
			continue;
		}
		else {
			int kek = dist[i][j];
			if (kek == -1 || kek >= p) {
				cout << matr[i][j] << '\n';
				continue;
			}
			else {
				int ans = matr[i][j] == '1';
				ans ^= (p - kek) & 1;
				cout << ans << '\n';
				continue;
			}
		}
	}
	return 0;
}