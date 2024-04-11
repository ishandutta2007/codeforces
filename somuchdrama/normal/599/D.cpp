#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

vector<pul> ans, really_ans;

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    ull x;
    cin >> x;
    for (ull n = 1; n * n * n <= x + x + x + x + x + x + x; ++n) {

        ull top = ((x + x) + n * n * (n - 1) - ((n * (n - 1) * (n + n - 1)) / 3));
        ull bot = (2 * n * n - (n - 1) * n);

        ull m = top / bot;
        if (m < n)
            break;
        if (m * bot == top) 
            ans.pb({n, m});
    }

    for (auto i : ans) {
        really_ans.pb(i);
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        if (ans[i].ff != ans[i].ss)
            really_ans.pb({ans[i].ss, ans[i].ff});
    }

    cout << really_ans.size() << '\n';
    for (auto i : really_ans)
        cout << i.ff << ' ' << i.ss << '\n';



    return 0;
}