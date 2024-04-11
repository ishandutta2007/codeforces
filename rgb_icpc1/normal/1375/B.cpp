#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i ++)
#define mx 100005
#define LL long long
using namespace std;


int n, m;
int a[350][350];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t, ii, jj, cnt;
	cin >> t;
	while(t --){
		cin >> n >> m;
		rep(i, 0, n) rep(j, 0, m ) cin >> a[i][j];
		bool can = 1;
		rep(i, 0, n){
			rep(j, 0, m) {
				cnt = 0;
				rep(k, 0, 4) {
					ii = i + dx[k]; jj = j + dy[k];
					if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
					cnt ++;
				}
				if(a[i][j] > cnt) {
					can = 0; break;
				}
				a[i][j] = cnt;
			}
			if(!can) break;
		}
		if(!can) {
			cout << "NO" << "\n";
		}
		else{
			cout << "YES" << "\n";
			rep(i, 0, n) {
				rep(j, 0, m) cout << a[i][j] << " ";
				cout << "\n";
			}
		}
	}
}