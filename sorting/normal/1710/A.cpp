#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(k);
        for(ll &x: a)
            cin >> x;

        ll take[2]{};
        bool not_two[2]{};
        for(ll &x: a){
            if(x < 2 * n)
                take[0] += 0;
            else{
                take[0] += x - (x % n);
                not_two[0] |= (x - (x % n)) >= 3 * n;
            }
        }
        for(ll &x: a){
            if(x < 2 * m)
                take[1] += 0;
            else{
                take[1] += x - (x % m);
                not_two[1] |= (x - (x % m)) >= 3 * m;
            }
        }

        auto check = [&](ll take, ll n, ll m, bool not_two){
            ll x = take / n;
            if(x < m)
                return false;
            if((x - m) & 1)
                return not_two;
            return true;
        };

        if(check(take[0], n, m, not_two[0]) || check(take[1], m, n, not_two[1])){
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
}