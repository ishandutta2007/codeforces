#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

void print(ll x) {
    ll cnt = 0;
    ll y = x;
    if (!y) {
        cnt = 1;
    }
    while (y) {
        cnt++;
        y /= 10;
    }
    for (int i = 0; i < 18 - cnt; i++) {
        cout << "0";
    }
    cout << x;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll sum = 0;
    ll n;
    cin >> n;
    ll add = 0;
    vector <ll> a(n);
    map <ll, ll> cnta, cntb;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        sum += x * (i - (n - 1LL - i));
        if (sum >= INF) {
            sum -= INF;
            add++;
        }
        if (sum <= -INF) {
            sum += INF;
            add--;
        }
        cnta[x]++;
    }
    auto cpya = cnta, cpyb = cntb;
    for (ll i = 0; i < n; i++) {
        ll x = a[i];
        cnta[x]--;
        for (ll j = -1; j <= 1; j++) {
            sum += cnta[x + j] * x;
            if (sum >= INF) {
                sum -= INF;
                add++;
            }
            sum -= cntb[x + j] * x;
            if (sum <= -INF) {
                sum += INF;
                add--;
            }
        }
        cntb[x]++;
    }
    //cout << add << "\n";
    if (add > 0) {
        if (sum < 0) {
            add--;
            sum += INF;
        }
        if (add) {
            cout << add;
            print(sum);
            return 0;
        }
    }
    if (add < 0) {
        if (sum > 0) {
            add++;
            sum -= INF;
        }
        if (add) {
            cout << add;
            print(abs(sum));
            return 0;
        }
    }
    cout << sum;
//    cnta = cpya, cntb = cpyb;
//    for (ll i = 0; i < n; i++) {
//        ll x = a[i];
//        cnta[x]--;
//        for (ll j = -1; j <= 1; j++) {
//            sum += cnta[x + j] * x;
//            sum -= cntb[x + j] * x;
//        }
//        cntb[x]++;
//    }
}