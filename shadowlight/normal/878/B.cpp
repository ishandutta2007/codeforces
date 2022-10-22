#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e5 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;

vector <ll> cnt;
ll k;

void clearing(vector <ll> &a) {
    vector <ll> mas = a;
    a.clear();
    cnt.clear();
    ll n = mas.size();
    ll pr = -1;
    for (int i = 0; i < n; i++) {
        ll x = mas[i];
        a.push_back(x);
        if (x != pr) {
            cnt.push_back(1);
            pr = x;
        } else {
            cnt.push_back(cnt.back() + 1);
        }
        if (cnt.back() == k) {
            for (ll j = 0; j < k; j++) {
                a.pop_back();
                cnt.pop_back();
            }
            if (a.size()) {
                pr = a.back();
            } else {
                pr = -1;
            }
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n, m;
    cin >> n >> k >> m;
    vector <ll> a;
    ll pr = -1;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    clearing(a);
    if (!a.size()) {
        cout << 0;
        return 0;
    }
//    for (int x : a) {
//        cout << x << " ";
//    }
//    cout << "\n";
//    for (int x : cnt) {
//        cout << x << " ";
//    }
//    cout << "\n";
    ll l = 0, r = a.size() - 1;
    ll ans = (r - l + 1) * m;
    while (true) {
        //cout << l << " " << r << "\n";
        ll sum = cnt[r];
        //cout << r << " " << cnt.size() << " " << cnt[r] << "\n";
        int l1 = l;
        while (l < r && a[l] == a[r]) {
            l++;
            sum++;
        }
        if (l == r) {
            sum = cnt[r];
            ans -= (sum * m / k * k);
            //cout << ans << "\n";
            if (sum * m % k == 0) {
                vector <ll> mas;
                for (ll i = 0; i < l1; i++) {
                    mas.push_back(a[i]);
                }
                for (ll j = r + 1; j < (int) a.size(); j++) {
                    mas.push_back(a[j]);
                }
                /*for (int x : mas) {
                    cout << x << " ";
                }
                cout << "\n";*/
                ans -= mas.size();
                clearing(mas);
                ans += mas.size();
            }
            cout << ans << "\n";
            return 0;
        }
        if (sum % k != 0) {
            ans -= (sum - sum % k) * (m - 1);
            cout << ans << "\n";
            return 0;
        }
        ans -= sum * (m - 1);
        r -= cnt[r];
    }
    assert(false);
}