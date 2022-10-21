#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what(x) cerr << #x << " is " << x << endl;
const int N = (int)1e5 + 50;
ll INF = (ll)1e18;

int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        ll dif = 0, mn = INF;
        for(int i = n - 1; i >= 0; i--) {
            dif = max(dif, a[i] - mn);
            mn = min(a[i], mn);
//            what(mn);
        }
//        what(dif);
        ll sec = 0;
        if(dif == 0) cout << "0\n";
        else {
            while(dif > (1LL << sec) - 1) {
                sec++;
            }
            cout << sec << '\n';
        }
    }

}