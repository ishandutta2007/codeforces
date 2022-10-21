#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
ll w;
int x[N];

void solve() {
    cin >> n >> w;
    rep(i, 0, n) cin >> x[i];
    vector<int> res;
    ll sum = 0;
    rep(i, 0, n) {
        if(x[i] > w) continue;
        if(x[i] * 2 >= w) {
            cout << "1\n" << i + 1 << "\n";
            return ;
        } else if(sum + x[i] <= w){
            res.push_back(i);
            sum += x[i];
        }
    }
    if(sum * 2 >= w) {
        cout << sz(res) << '\n';
        for(int x : res) cout << x + 1 << " ";
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    while(T--) solve();



}