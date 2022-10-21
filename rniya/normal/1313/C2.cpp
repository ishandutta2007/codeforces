#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> m(n),left(n),right(n),ans(n);
    for (int i=0;i<n;++i) cin >> m[i];
    stack<int> st;
    st.push(-1);
    for (int i=0;i<n;++i){
        left[i]=(i?left[i-1]:0);
        while(1<st.size()&&m[i]<m[st.top()]){
            int t=st.top(); st.pop();
            left[i]-=m[t]*(t-st.top());
        }
        left[i]+=m[i]*(i-st.top());
        st.push(i);
    }
    st=decltype(st)();
    st.push(n);
    for (int i=n-1;i>=0;--i){
        right[i]=(i<n-1?right[i+1]:0);
        while(1<st.size()&&m[i]<m[st.top()]){
            int t=st.top(); st.pop();
            right[i]-=m[t]*(st.top()-t);
        }
        right[i]+=m[i]*(st.top()-i);
        st.push(i);
    }
    ll M=0,center;
    for (int i=0;i<n;++i) if (M<left[i]+right[i]-m[i]){
        M=left[i]+right[i]-m[i]; center=i;
    }
    ans[center]=m[center];
    for (int i=center+1;i<n;++i) ans[i]=min(ans[i-1],m[i]);
    for (int i=center-1;i>=0;--i) ans[i]=min(ans[i+1],m[i]);
    for (int i=0;i<n;++i) cout << ans[i] << (i!=n-1?' ':'\n');
}