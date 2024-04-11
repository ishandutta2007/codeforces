#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <cassert>
#include <list>
//#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    clock_t start = clock();
#else
	
    //freopen("taxi.in", "r", stdin);
    //freopen("taxi.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}

string s[1010];
int d[1010][1010];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
bool correct(const pi& a) {
	return a.first >= 0 && a.first < n && a.second >= 0 && a.second < m && s[a.first][a.second] != 'T';
}
 
void solve() {
	
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	
	queue<pi> q;
	memset(d, -1, sizeof d);
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(s[i][j] == 'E') {
				q.push(pi(i, j));
				d[i][j] = 0;
				break;
			}
		}
	}
	
	
	
	
	
	while(!q.empty()) {
		pi cur = q.front();
		q.pop();
		for(int dd = 0;dd < 4; ++dd) {
			pi nex = mp(cur.first + dx[dd], cur.second + dy[dd]);
			if(correct(nex) && d[nex.first][nex.second] == -1) {
				d[nex.first][nex.second] = d[cur.first][cur.second] + 1;
				q.push(nex);
			}
		}
	}
	
	li ans = 0;
	int myDist = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			if(s[i][j] == 'S') {
				myDist = d[i][j];
				break;
			}
		}
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			if(s[i][j] != 'S' && s[i][j] !=  'E'  && d[i][j] != -1 && d[i][j] <= myDist) {
				//cerr << i << ' '<< j <<  ' ' << ans << endl ;
				ans += (s[i][j] - '0');
			}
		}
	
	cout << ans;
	
	
}