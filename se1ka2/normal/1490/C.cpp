#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    set<ll> st;
    for(ll i = 1; i <= 10000; i++) st.insert(i * i * i);
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        bool f = false;
        for(ll i = 1; i <= 10000; i++){
            ll y = i * i * i;
            if(y > x) break;
            if(st.find(x - y) != st.end()){
                f = true;
                break;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}