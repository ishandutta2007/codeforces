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
        int n, m; cin >> n >> m;
        priority_queue<int, vector<int>, greater<int> > que;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                que.push(max(i, n - 1 - i) + max(j, m - j - 1));
            }
        }
        while (!que.empty()){
            cout << que.top() << sp;
            que.pop();
        }
        cout << ln;
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