#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

const int N = (int)1e3;

int n;
int res[N];

ll getres(int n, int k) {
    return n / k * (k - 1) + max(0, n % k - 1) - (k - 1);
}

int mp[N], wantmp[N];
int cnt = 0;


int main() {
    cin >> n;
    int mxi = 1;
    for(int i = 2; i <= n; i++) {
        if(getres(n, i) > getres(n, mxi)) mxi = i;
    }
    ll fres = getres(n, mxi);
    int k = mxi;
//    cout << k << endl;
    for(int i = 0; i < n; i++) wantmp[i] = (i % k != 0);

    while(true) {
        if(cnt >= fres) {
            cout << 0 << endl;
            fflush(stdout);
            return 0;
        }

        vector<int> ask;
        for(int i = 0; i < n && ask.size() < k; i++) {
            if(wantmp[i] && !mp[i]) {
                ask.push_back(i);
                mp[i] = 1;
                cnt++;
            }
        }
        cout << k << " ";
        for(int x : ask) cout << x + 1 << " ";
        cout << endl;
        fflush(stdout);
        int val;
        cin >> val;
        assert(val != -1);
        val--;
        for(int j = 0; j < k; j++) {
            cnt -= mp[(val + j) % n];
            mp[(val + j) % n] = 0;
        }

    }


}