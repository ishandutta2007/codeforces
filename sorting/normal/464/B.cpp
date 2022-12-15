#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
const int N = 10;

array<int, 3> order[6], c[N], o[N];
int n = 8;
ll d[N][N];

ll get_dist(array<int, 3> a, array<int, 3> b){
    ll dist = 0;
    for(int i = 0; i < 3; ++i)
        dist += (ll)(a[i] - b[i]) * (a[i] - b[i]);
    return dist;
}

bool check(){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            d[i][j] = get_dist(c[i], c[j]);
    for(int i = 0; i < n; ++i){
        sort(d[i], d[i] + n);
    }

    for(int i = 0; i <= 0; ++i){
        if(d[i][0] != 0) return false;
        if(d[i][1] == 0) return false;
        if(d[i][3] != d[i][1]) return false;
        if(d[i][4] != d[i][6] || d[i][4] != d[i][1] * 2) return false;
        if(d[i][7] != d[i][1] * 3) return false;
    }

    for(int i = 1; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(d[i][j] != d[0][j])
                return false;
    return true;
}

void solve(int pos){
    if(pos == n){
        if(check()){
            cout << "YES\n";
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < 3; ++j)
                    cout << c[i][j] << " ";
                cout << "\n";
            }
            exit(0);
        }
        return;
    }

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 3; ++j)
            c[pos][j] = o[pos][order[i][j]];
        solve(pos + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    order[0] = {0, 1, 2};
    for(int i = 1; i < 6; ++i){
        order[i] = order[i - 1];
        next_permutation(order[i].begin(), order[i].end());
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 3; ++j){
            cin >> c[i][j];
            o[i][j] = c[i][j];
        }

    solve(1);
    cout << "NO\n";
}