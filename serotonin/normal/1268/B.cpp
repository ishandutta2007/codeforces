#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

int main()
{
    ll n,ans=0;
    cin >> n;
    stack <ll> st;
    for(ll i=0; i<n; i++) {
        ll x;
        scanf("%lld", &x);
        ans+=x;
        x&=1;
        if(!st.empty() && st.top()==x) st.pop();
        else st.push(x);
    }
    while(!st.empty()) ans-=st.top(), st.pop();
    cout << ans/2 << endl;
}