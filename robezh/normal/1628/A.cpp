#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50;
int n, a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vi cnt(n + 1, 0);
        rep(i, 0, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int cur = 0;
        vi res;
        while(cur < n) {
            int mx = -1;
            while(mx + 1 <= n && cnt[mx + 1]) mx++;
//            cout << cur << " " << mx << endl;

            int i = cur;
            vi vis(mx + 1, 0);
            int rem = mx + 1;
            while(rem || i == cur) {
                if(a[i] <= mx && !vis[a[i]]) {
                    vis[a[i]] = 1;
                    rem--;
                }
                cnt[a[i]]--;
                i++;
            }
            cur = i;
            res.push_back(mx + 1);
        }
        cout << sz(res) << '\n';
        for (int x : res) cout << x << " ";
        cout << '\n';
    }


}