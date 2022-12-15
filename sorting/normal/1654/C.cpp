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
        int n;
        cin >> n;

        map<ll, ll> cnt;

        ll sum = 0;

        vector<ll> a(n);
        for(ll &x: a){
            cin >> x;
            sum += x;
            cnt[x]++;
        }
        
        vector<ll> to_split;
        to_split.push_back(sum);
        
        bool ok = true;
        ll total = 1;
        while(!to_split.empty() && total <= n){
            ll x = to_split.back();
            to_split.pop_back();

            if(cnt[x]){
                --cnt[x];
            }
            else{
                to_split.push_back(x / 2);
                to_split.push_back((x + 1) / 2);
                ++total;
            }
        }

        if(total == n)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}