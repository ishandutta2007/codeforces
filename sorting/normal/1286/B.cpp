#include <bits/stdc++.h>

using namespace std;

const int k_N = 2000 + 3;

int n;
vector<int> adjacent[k_N];
int c[k_N];

vector<int> v[k_N];
int answer[k_N];

void solve(int node){
    for(int to: adjacent[node]){
        solve(to);
        for(int x: v[to])
            v[node].push_back(x);
    }

    if(c[node] > v[node].size()){
        cout << "NO\n";
        exit(0);
    }

    v[node].insert(v[node].begin() + c[node], node);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int root = -1;
    for(int i = 1; i <= n; ++i){
        int p;
        cin >> p >> c[i];

        if(p)
            adjacent[p].push_back(i);
        else
            root = i;
    }

    solve(root);

    for(int i = 0; i < n; ++i)
        answer[v[root][i]] = i + 1;

    cout << "YES\n";
    for(int i = 1; i <= n; ++i)
        cout << answer[i] << " ";
    cout << "\n";
}