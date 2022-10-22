#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    set<ll> st;
    ll s = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(st.find(-(a[i] + s)) != st.end()){
            ans++;
            st.clear();
            s = 0;
        }
        s += a[i];
        st.insert(a[i] - s);
    }
    cout << ans << endl;
}