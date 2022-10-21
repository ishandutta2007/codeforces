#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 45;
const ll PW20 = (1 << 20);

int n,m;
bool a[N][N];
bool ls[N];
int dp[(1 << 20) + 5];
ll g[N];
int tcnt = 0;
map<string, int> mp;

int getid(const string &s) {
    if(!mp.count(s)) return mp[s] = tcnt++;
    else return mp[s];
}

int get_v(ll mask) {
    int cnt = 0;
    while(mask > 0){mask /= 2; cnt++;}
    return cnt - 1;
}

int get(ll mask) {
    if(mask < PW20 && dp[mask] != -1) return dp[mask];
    if(mask == 0) return 0;
    int v = get_v(mask);
    int res = max(get(mask - (1LL << v)), 1 + get(mask & g[v]));
    if(mask < PW20) dp[mask] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int k; string s;
        cin >> k;
        if(k == 1){
            vector<int> V;
            for(int j = 0; j < m; j++) if(ls[j]) V.push_back(j);
            for(int x : V) {
                for(int y : V) a[x][y] |= 1;
            }
            memset(ls, false, sizeof(ls));
        }
        else {
            cin >> s;
            ls[getid(s)] = true;
        }
    }
    vector<int> V;
    for(int j = 0; j < m; j++) if(ls[j]) V.push_back(j);
    for(int x : V) {
        for(int y : V) a[x][y] = true;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++){
            if (i == j) a[i][j] = false;
            else a[i][j] ^= 1;
        }
        for(int j = 0; j < m; j++) {
            if(a[i][j]) g[i] |= (1LL << j);
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << get((1LL << m) - 1) << endl;

}