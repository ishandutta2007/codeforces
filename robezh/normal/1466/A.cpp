#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = 55;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        map<int, int> mp;
        rep(i, 0, n) {
            cin >> a[i];
            rep(j, 0, i) {
                mp[a[i] - a[j]]++;
            }
        }
        cout << mp.size() << '\n';
    }


}