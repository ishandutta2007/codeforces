// Oh my lord I need you by my side...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 3010;

vector<int> inp[maxn];
ll sum[maxn];
vector<pll> task[4 * maxn];
int n, k;

void add(int f, int s, pll p, int l = 0, int r = n, int id = 1){
    if(f >= s || l >= r || s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	task[id].PB(p);
	return;
    }
    int mid = (l+r) >> 1;
    add(f, s, p, l, mid, 2*id);
    add(f, s, p, mid, r, 2*id+1);    
}

ll backup[20][maxn], dp[maxn];
ll ANS;

void add_knapsack(pll p){
    for(int i = k; i - p.F >= 0; i--){
	dp[i] = max(dp[i], dp[i - p.F] + p.S);
    }
}
void dfs(int l = 0, int r = n, int id = 1, int h = 0){
    memcpy(backup[h], dp, sizeof dp);
    for(pll p : task[id])
	add_knapsack(p);    
    if(r-l == 1){
	ANS = max(ANS, dp[k]);
	ll S = 0;
	for(int i = 0; i < sz(inp[l]); i++){
	    S+= inp[l][i];
	    if(i + 1 <= k)
		ANS = max(ANS, S + dp[k - i - 1]);
	}
	memcpy(dp, backup[h], sizeof dp);
	return;
    }
    int mid = (l+r) >> 1;
    dfs(l, mid, 2*id, h + 1);
    dfs(mid, r, 2*id+1, h + 1);
    memcpy(dp, backup[h], sizeof dp);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
   
    cin >> n >> k;
    for(int i = 0; i < n; i++){
	int c;
	cin >> c;
	inp[i].resize(c);
	for(int j = 0; j < c; j++){
	    cin >> inp[i][j];
	    sum[i]+= inp[i][j];
	}
	add(0, i, {c, sum[i]});
	add(i+1, n, {c, sum[i]});
    }
    dfs();
    return cout << ANS << endl, 0;
}