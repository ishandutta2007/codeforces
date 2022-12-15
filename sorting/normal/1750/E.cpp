#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 9;
typedef long long ll;

int n;

struct Fenwick{
    ll a[2 * N];

    void reset(){
        for(int i = 0; i < 2 * (n + 2); ++i)
            a[i] = 0;
    }

    void update(ll i, ll v){
        i += n + 2;
        for(; i < 2 * (n + 2); i += i & -i)
            a[i] += v;
    }
    ll query(ll i){
        ll res = 0;
        i += n + 2;
        for(; i >= 1; i -= i & -i)
            res += a[i];
        return res;
    }
    ll query(ll from, ll to){
        return query(to) - query(from - 1);
    }
} f1, f2;

string s;
vector<int> v;

void solve(){
    cin >> n >> s;
    v.resize(n);
    for(int i = 0; i < n; ++i){
        v[i] = (s[i] == '(') ? 1 : -1;
    }

    vector<pair<int ,int>> ranges;
    ll ans = 0, first = 0, sum = 0;
    ranges.push_back({n - 1, n - 1});
    if(v[n - 1] == -1){
        first = 1;
        sum += 1;
        ans += sum;
    }

    for(int i = n - 2; i >= 0; --i){
        if(v[i] == -1){
            if(first == 0){
                ranges.back().first = i;
                sum += n - i - 1;
                sum += 1;
                ans += sum;
            }
            else{
                ranges.push_back({i, i});
                sum += n - i - 1;
                sum += 1;
                ans += sum;
            }
            first = 1;
        }
        else{
            if(first == 0){
                auto [l, r] = ranges.back();
                sum -= n - 1 - i - (r - l + 1);
                
                ranges.pop_back();
                if(!ranges.empty()){
                    ranges.back().first = l;
                }
                else
                    ranges.push_back({l, r});
            }
            else{
                sum -= n - i - 1;
                first -= 1;
            }
            ans += sum;

            ranges.back().first = i;
        }
    }

    // cout << ans << "\n";

    sum = 0;
    f1.update(sum, 1);
    f2.update(sum, 0);
    for(int i = 0; i < n; ++i){
        sum += v[i];
        // cout << sum << " sum" << endl;
        ans += sum * f1.query(sum);
        ans -= f2.query(sum);

        f1.update(sum, 1);
        f2.update(sum, sum);
        // cout << ans << " ans" << endl;
    }

    f1.reset();
    f2.reset();

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
}