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
        ll n, x;
        cin >> n >> x;

        multiset<ll> s;
        vector<ll> a(n);
        for(ll &el: a){
            cin >> el;
            s.insert(el);
        }

        int cnt = 0;
        auto it = s.begin();
        while(it != s.end()){
            ll t = *it;
            if(s.find(t * x) != s.end()){
                auto it2 = s.find(t * x);
                auto it3 = it;
                ++it;
                if(it2 == it) ++it;
                s.erase(it2);
                s.erase(it3);
            }
            else{
                auto it3 = it;
                ++it;
                s.erase(it3);
                ++cnt;
            }
        }

        cout << cnt << "\n";
    }
}