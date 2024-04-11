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
#include <list>
#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

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
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;

}

bool matrix[111][111];
set<int> lang[111];
bool used[111];
int n, m;
void dfs(int v){
    if(used[v])
        return;
    used[v] = true;
    for(int i = 0; i < n; ++i){
        if(matrix[v][i])
            dfs(i);
    }
}
void solve() {
    
    cin >> n >> m;
    bool knowAny = false;
    for(int i = 0; i < n; ++i){
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j){
            knowAny = true;
            int a;
            cin >> a;
            --a;
            lang[i].insert(a);
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) if(i != j){
            for(int k = 0; k < m; ++k){
                if(lang[i].find(k) != lang[i].end() && lang[j].find(k) != lang[j].end()){
                    matrix[i][j] = true;
                    break;
                }
            }
        }
    }
    
    if(!knowAny){
        cout << n;
        return;
    }
    
    int ans = -1;
    
    for(int i = 0; i < n; ++i){
        if(!used[i]){
            dfs(i);
            ++ans;
        }
    }
    
    
    cout << ans;
}