#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

void upd(map<ll, ll> &mp, ll idx, ll val){
    if(!mp.count(idx))
        mp[idx] = val;
    else
        check_max(mp[idx], val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const ll INF = 1e18;

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        vector<ll> a(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            a[i] += a[i - 1];
        }

        map<ll, ll> sm, eq, bi;
        eq[a[n]] = 0;
        sm[a[n]] = -n;
        bi[a[n]] = n;

        ll dp;
        for(int i = n - 1; i >= 0; --i){
            // cout << i << endl;

            dp = -INF;
            if(eq.count(a[i]))
                check_max(dp, eq[a[i]]);
            // cout << "eq " << dp << endl;

            auto it1 = bi.upper_bound(a[i]);
            if(it1 != bi.end())
                check_max(dp, it1->second - i);
            // cout << "bi " << dp << endl;

            auto it2 = sm.lower_bound(a[i]);
            if(it2 != sm.begin()){
                --it2;
                check_max(dp, it2->second + i);
            }
            // cout << "sm " << dp << endl;

            upd(eq, a[i], dp);
            upd(bi, a[i], dp + i);
            upd(sm, a[i], dp - i);

            it1 = bi.find(a[i]);
            if(it1 != bi.begin()){
                --it1;
                while(true){
                    if(it1->second < bi[a[i]]){
                        auto it_cp = it1;
                        if(it1 == bi.begin()){
                            bi.erase(it_cp);
                            break;
                        }
                        else{
                            --it1;
                            bi.erase(it_cp);
                        }
                    }
                    else break;
                }
            }

            
            // cout << "sm[" << a[i] << "] " << sm[a[i]] << endl;
            it2 = sm.find(a[i]);
            ++it2;
            while(it2 != sm.end()){
                if(it2->second < sm[a[i]]){
                    auto it_cp = it2;
                    ++it2;
                    sm.erase(it_cp);
                }
                else break;
            }

            // cout << dp << endl;
        }

        cout << dp << "\n";
    }
}