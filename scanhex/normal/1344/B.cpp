#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=1010;
string matr[N];

vector<int> dx = {0,1,0,-1}, dy = {1,0,-1,0};
bool used[N][N];
int n,m;
void dfs(int x,int y) {
	if (used[x][y] || matr[x][y] == '.')
		return;
	used[x][y]=true;
	for(int i=0;i<4;++i){
		 int xx=x+dx[i],yy=y+dy[i];
		 if (xx >= 0 && yy >= 0 && xx < n && yy < m)
			 dfs(xx,yy);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;++i)
		cin >> matr[i];
	int cc = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cc += matr[i][j] == '#';
	if (cc == 0){
		 cout << 0 << '\n';
		 return 0;
	}
	cc=0;
	int cr=0;
	for(int i=0;i<n;++i){
		int mn=1e9,mx=-1,cnt=0;
		for(int j=0;j<m;++j)
			if (matr[i][j] == '#')
				mn = min(mn, j), mx = max(mx, j), ++cnt;
		if (cnt == 0) {
			++cr;
		}
		if (mx != -1 && cnt != mx - mn + 1) {
			 cout << -1 << '\n';
			 return 0;
		}
	}
	for(int i=0;i<m;++i){
		int mn=1e9,mx=-1,cnt=0;
		for(int j=0;j<n;++j)
			if (matr[j][i] == '#')
				mn = min(mn, j), mx = max(mx, j), ++cnt;
		if (cnt == 0) {
			++cc;
		}
		if (mx != -1 && cnt != mx - mn + 1) {
			 cout << -1 << '\n';
			 return 0;
		}
	}
	if (cr == 0 && cc > 0 || cc == 0 && cr > 0) {
		 cout << -1 << '\n';
		 return 0;
	}
	int c=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			if (matr[i][j] == '#' && !used[i][j])
				++c, dfs(i,j);
	}
	cout << c << '\n';
	return 0;
}