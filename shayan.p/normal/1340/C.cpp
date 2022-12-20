// Never let them see you bleed...
// Shayan.P  2020-04-23

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e4 + 10, maxg = 1010, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn];
int dp[maxn][maxg];
bool mark[maxn][maxg];

deque<pii> D;

void better(int pos, int rm, int x, bool is){
    if(mark[pos][rm])
	return;
    mark[pos][rm] = 1;
    dp[pos][rm] = x;
    if(is)
	D.push_front({pos, rm});
    else
	D.push_back({pos, rm});
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	cin >> a[i];
    }
    int g, r;
    cin >> g >> r;
    sort(a, a+m);
    m = unique(a, a+m) - a;
    for(int i = 0; i < m; i++){
	for(int j = 0; j <= g; j++){
	    dp[i][j] = inf;
	}
    }
    dp[0][g] = 0;
    D.push_back({0, g});
    mark[0][g] = 1;
    
    while(sz(D)){
	int pos = D.back().F, rm = D.back().S;
	D.pop_back();
	if(rm == 0)
	    better(pos, g, dp[pos][rm] + 1, 1);
	if(pos != 0 && a[pos]-a[pos-1] <= rm)
	    better(pos-1, rm - (a[pos]-a[pos-1]), dp[pos][rm], 0);
	if(pos != m-1 && a[pos+1]-a[pos] <= rm)
	    better(pos+1, rm - (a[pos+1]-a[pos]), dp[pos][rm], 0);
    }
    int ans = inf;
    for(int i = 0; i <= g; i++){
	if(dp[m-1][i] != inf)
	    ans = min(ans, dp[m-1][i] * (r+g) + (g-i));
    }
    if(ans == inf)
	cout << -1 << endl;
    else
	cout << ans << endl;
    return 0;
}