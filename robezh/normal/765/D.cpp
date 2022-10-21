#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 500;

int n;
int h[MAXN], g[MAXN], f[MAXN];
map<int, int> mp;
set<int> S;
int m = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> f[i];
    for(int i = 1; i <= n; i++){
        if(f[f[i]] == f[i]) S.insert(f[i]);
        else return !printf("-1");
    }
    for(int s : S) h[++m] = s, mp[s] = m;
    for(int i = 1; i <= n; i++){
        g[i] = mp[f[i]];
    }
    cout << m << endl;
    for(int i = 1; i <= n; i++) cout << g[i] << " ";
    cout << endl;
    for(int i = 1; i <= m; i++) cout << h[i] << " ";
}