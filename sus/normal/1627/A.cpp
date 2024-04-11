#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    int t; cin >> t;
    while(t--){
        int n, m, r, c; cin >> n >> m >> r >> c;
        char ch[n][m];
        r--;
        c--;
        vi x(n);
        vi y(m);
        int e = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> ch[i][j];
                if(ch[i][j]=='B'){
                    e = 1;
                    y[j] = 1;
                    x[i] = 1;
                }
            }
        }
        if(e==0) cout << -1 << ln;
        else if (ch[r][c]=='B') cout << 0 << ln;
        else if(x[r]==1 || y[c]==1) cout << 1 << ln;
        else cout << 2 << ln;

    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}