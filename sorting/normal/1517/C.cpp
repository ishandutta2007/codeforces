#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 500 + 3;

int p[N], n, a[N][N];

void dfs(int x, int y, int val, int rem){
    a[x][y] = val;
    if(!rem) return;
    if(y != 1 && !a[x][y - 1]){
        dfs(x, y - 1, val, rem - 1);
        return;
    }
    dfs(x + 1, y, val, rem - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> p[i];

    for(int i = 1; i <= n; ++i)
        dfs(i, i, p[i], p[i] - 1);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}