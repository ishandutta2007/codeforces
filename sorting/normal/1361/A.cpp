#include <bits/stdc++.h>

using namespace std;

const int k_N = 5e5 + 7;

int n, m;
vector<int> adjacent[k_N];
int t[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i)
        cin >> t[i];

    for(int i = 1; i <= n; ++i){
        for(int &x: adjacent[i])
            x = t[x];

        sort(adjacent[i].begin(), adjacent[i].end());
        int pr = 0;
        for(int x: adjacent[i]){
            if(x > pr + 1)
                break;
            pr = x;
        }

        //cout << t[i] << " - " << pr + 1 << endl;

        if(t[i] != pr + 1){
            cout << "-1\n";
            return 0;
        }
    }

    static int permutation[k_N];
    for(int i = 1; i <= n; ++i)
        permutation[i] = i;

    sort(permutation + 1, permutation + 1 + n, [](int lvalue, int rvalue){  
        return t[lvalue] < t[rvalue];
    });

    for(int i = 1; i <= n; ++i)
        cout << permutation[i] << " ";
    cout << "\n"; 
}