#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()

int n;
string s[60], ans[110];
bool atk[60][60];

bool in(int i, int j){ return i >= 0 && i < n && j >= 0 && j < n; }

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];
    rep(i, n * 2 - 1){
	ans[i].resize(n * 2 - 1);
	rep(j, n * 2 - 1) ans[i][j] = '.';
    }
    ans[n - 1][n - 1] = 'o';

    for(int dy = -n + 1; dy <= n - 1; ++dy){
	for(int dx = -n + 1; dx <= n - 1; ++dx){
	    if(dx == 0 && dy == 0) continue;
	    bool ok = 1;
	    rep(i, n) rep(j, n) if(s[i][j] == 'o'){
		int ni = i + dy, nj = j + dx;
		if(in(ni, nj) && s[ni][nj] == '.') ok = 0;
	    }
	    if(ok) ans[n - 1 + dy][n - 1 + dx] = 'x';
	}
    }

    for(int dy = -n + 1; dy <= n - 1; ++dy){
	for(int dx = -n + 1; dx <= n - 1; ++dx){
	    if(ans[n - 1 + dy][n - 1 + dx] == 'x'){
		rep(i, n) rep(j, n) if(s[i][j] == 'o'){
		    int ni = i + dy, nj = j + dx;
		    if(in(ni, nj)) atk[ni][nj] = 1;
		}
	    }
	}
    }

    rep(i, n) rep(j, n) if(s[i][j] == 'x' && !atk[i][j]){
	puts("NO");
	return 0;
    }

    puts("YES");
    rep(i, n * 2 - 1) cout << ans[i] << endl;

    return 0;
}