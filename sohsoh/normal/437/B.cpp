/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 30;

stack<ll> nums[LOG];
ll sum, lim;

int main() {
    fast_io;
    cin >> sum >> lim;
    for (int i = 1; i <= lim; i++) {
        ll ind = 0;
        ll n = i;
        while (n % 2 == 0) {
            n /= 2;
            ind++;
        }

        nums[ind].push(i);
    }

    vector<ll> ans;
    ll ind = LOG - 1;
    while (ind >= 0) {
        ll p = pow(2ll, ind);
        while (sum - p >= 0 && !nums[ind].empty()) {
            ans.push_back(nums[ind].top());
            sum -= p;
            nums[ind].pop();
        }

        ind--;
    }

    if (sum > 0) return cout << -1 << endl, 0;
    cout << ans.size() << endl;
    for (ll e : ans) cout << e << sep;
    cout << endl;
    return 0;
}