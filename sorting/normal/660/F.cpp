#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

struct CHT{
    deque<pair<ll, ll>> lines;

    ll ip(pair<ll, ll> l1, pair<ll, ll> l2){
        return (l1.second - l2.second) / (l2.first - l1.first); 
    }

    ll eval(pair<ll, ll> l, ll x){
        return l.first * x + l.second;
    }

    void add(ll k, ll b){
        while(lines.size() >= 2 && ip(lines[lines.size() - 2], lines.back()) >= ip(lines.back(), {k, b}))
            lines.pop_back();
        lines.push_back({k, b});
    }

    ll query(ll x){
        ll l = 0, r = (int)lines.size() - 1;
        while(l != r){
            int mid = (l + r) >> 1;
            if(eval(lines[mid], x) >= eval(lines[mid + 1], x))
                r = mid;
            else
                l = mid + 1;
        }
        return eval(lines[l], x);
    }
} cht;

const int N = 2e5 + 3;

ll n, a[N], p[N], q[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        q[i] = q[i - 1] + a[i] * i;
    }

    ll ans = 0;
    for(int r = 1; r <= n; ++r){
        ll l = r - 1;
        cht.add(l, -q[l] + p[l] * l);
        check_max(ans, cht.query(-p[r]) + q[r]);
    }
    cout << ans << "\n";
}