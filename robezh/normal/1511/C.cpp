#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];

    while(q--) {
        int t; cin >> t;
        rep(i, 0, n) {
            if(a[i] == t) {
                cout << i + 1 << " ";
                int cur = i;
                while(cur) {
                    swap(a[cur], a[cur - 1]);
                    cur--;
                }
                break;
            }
        }
    }

}