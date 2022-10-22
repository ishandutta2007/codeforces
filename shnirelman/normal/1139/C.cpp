#include <bits/stdc++.h>

using namespace std;

long long M = 1e9 + 7;

long long pow1(long long n, long long k){
    if(k == 1)return n;

    long long pw = pow1(n, k / 2);
    if(k & 1)return pw * pw % M * n % M;
    else return pw * pw % M;
}

vector<vector<pair<int, int> > > a;

vector<int> b;

void dfs(int v, int p, int w){
    b[w]++;
    //cout << v << ' ' << p << ' ' << w << endl;
    for(int i = 0; i < a[v].size(); i++){
        int u = a[v][i].first, x = a[v][i].second;
        if(u == p)continue;
//cout << u << endl;
        if(x == 1){
            b.push_back(0);
            //cout << b.size() - 1 << ' ' <<  v << ' ' << u << endl;
            dfs(u, v, b.size() - 1);
        }
        else{
            dfs(u, v, w);
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;



    a.resize(n);
    for(int i = 0; i < n - 1; i++){
        int v, u, x;
        cin >> v >> u >> x;
        v--;
        u--;

        a[v].push_back({u, x});
        a[u].push_back({v, x});
    }

    b.push_back(0);
    dfs(0, 0, 0);

    long long ans = pow1(n, k);
    for(int i = 0; i < b.size(); i++){
            //cout << b[i] << endl;
        ans = (ans - pow1(b[i], k));
        if(ans < 0)ans += M;
    }

    cout << ans;
}