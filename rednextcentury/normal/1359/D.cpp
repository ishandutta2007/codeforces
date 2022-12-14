#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L (x*2)
#define R (L+1)
#define mid ((l+r)/2)
int a[1000000];
int pre[1000000];
int mn[1000000];
int mx[1000000];
void build(int x,int l,int r){
    if (l==r) mn[x]=mx[x] = pre[l];
    else {
        build(L,l,mid);
        build(R,mid+1,r);
        mx[x]=max(mx[L],mx[R]);
        mn[x]=min(mn[L],mn[R]);
    }
}
int getMn(int x,int l,int r,int s,int e){
    if (l>e || r<s)return 1e9;
    if (l>=s && r<=e) return mn[x];
    return min(getMn(L,l,mid,s,e), getMn(R,mid+1,r,s,e));
}
int getMx(int x,int l,int r,int s,int e){
    if (l>e || r<s)return -1e9;
    if (l>=s && r<=e) return mx[x];
    return max(getMx(L,l,mid,s,e), getMx(R,mid+1,r,s,e));
}
int S[1000000];
int E[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    build(1,0,n);
    stack<int> st;
    for (int i=1;i<=n;i++){
        while(!st.empty() && a[i]>=a[st.top()])
            st.pop();
        if (st.empty()) S[i] = 0;
        else S[i] = st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    for (int i=n;i>=1;i--){
        while(!st.empty() && a[i]>=a[st.top()])
            st.pop();
        if (st.empty()) E[i] = n+1;
        else E[i] = st.top();
        st.push(i);
    }
    ll ret = -1e18;
    for (int i=1;i<=n;i++){
        int l = S[i], r = E[i];
        int Mn = getMn(1,0,n,l,i-1);
        int Mx = getMx(1,0,n,i,r-1);
        ret=max(ret,0LL+ Mx-Mn-a[i]);
    }
    cout<<ret<<endl;
}