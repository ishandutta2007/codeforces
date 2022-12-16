// And you curse yourself for things you never done
// Shayan.P  2020-08-12

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<pii> v[maxn], g[maxn];

int cnt[10][10];
int M[10][10][10], W[10];
int k;

int ans;

void go(int pos = 0){
    if(pos == k){
	ans++;
	return;
    }
    int msk = (1<<(pos+1))-1;
    for(int i = 0; i < pos; i++){
	msk&= M[i][W[i]][pos];
    }
    for(int i = 0; i <= pos; i++){
	if(bit(msk, i) && bit(M[pos][i][pos], i)){
	    W[pos] = i;
	    go(pos+1);
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
	    for(int k = 0; k < 10; k++)
		M[i][j][k] = (1<<(k+1)) - 1;
    int n, m;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;
	v[a].PB({c, b});
    }
    for(int i = 1; i <= n; i++){
	sort(v[i].begin(), v[i].end());
	for(int j = 0; j < sz(v[i]); j++){
	    g[v[i][j].S].PB({sz(v[i])-1, j});
	}
    }
    for(int i = 1; i <= n; i++){
	memset(cnt, 0, sizeof cnt);
	for(pii p : g[i]){
	    cnt[p.F][p.S]++;
	}
	for(pii p : g[i]){
	    --cnt[p.F][p.S];
	    for(int j = 0; j < k; j++){
		int msk = 0;
		for(int w = 0; w <= j; w++){
		    msk|= (cnt[j][w] == 0) << w;
		}
		M[p.F][p.S][j]&= msk;
	    }
	    ++cnt[p.F][p.S];
	}
    }
    go();
    return cout << ans << endl, 0;
}