#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e2 + 3;
int n, m;
array<int, 3> p[N * N];
int ans[N][N], ptr[N], a[N][N];
bool vis[N][N];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            vis[i][j] = false;
    for(int i = 0; i < n; ++i)
        ptr[i] = 0;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            p[i * m + j][0] = a[i][j];
            p[i * m + j][1] = i;
            p[i * m + j][2] = j;
        }

    sort(p, p + n * m);
    for(int i = 0; i < m; ++i)
        vis[p[i][1]][p[i][2]] = true;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(p[i][1] == j){
                ans[j][i] = p[i][0];
                continue;
            }
            for(; vis[j][ptr[j]]; ++ptr[j]);
            ans[j][i] = a[j][ptr[j]];
            ++ptr[j];
        }
    }        

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)  solve();
}