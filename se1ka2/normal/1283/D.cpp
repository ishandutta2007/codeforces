#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll x[200005];
    set<ll> st1;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        st1.insert(x[i]);
    }
    int next[200005];
    int last[200005];
    for(int i = 0; i < n; i++){
        next[i] = i + 1;
        last[i] = i - 1;
    }
    next[n - 1] = 0;
    last[0] = n - 1;
    ll i = 0, k = 1;
    ll ans = 0;
    set<ll> st2;
    while(m){
        bool f = false;
        if(st1.find(x[i] - k) == st1.end() && st2.find(x[i] - k) == st2.end()){
            f = true;
            st2.insert(x[i] - k);
            ans += k;
            m--;
        }
        if(m == 0) break;
        if(st1.find(x[i] + k) == st1.end() && st2.find(x[i] + k) == st2.end()){
            f = true;
            st2.insert(x[i] + k);
            ans += k;
            m--;
        }
        if(!f){
            next[last[i]] = next[i];
            last[next[i]] = last[i];
        }
        if(i >= next[i]) k++;
        i = next[i];
    }
    cout << ans << endl;
    for(auto itr = st2.begin(); itr != st2.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
}