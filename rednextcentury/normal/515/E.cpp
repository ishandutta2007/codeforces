#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll b[1000000];
ll h[1000000];
ll d[1000000];
ll loc[1000000];
int l[1000000];
int r[1000000];
ll ret[1000000];
ll best[1000000];
ll mxA[1000000];
ll mxB[1000000];
void solve(int s,int e,vector<int> &Q){
    if (s>e)return;
    vector<int> L,R;
    int mid = (s+e)/2;
    mxA[mid] = a[mid];
    mxB[mid] = -1e17;
    ll cur = -1e17;
    best[mid] = -1e17;
    for (int i=mid-1;i>=s;i--) {
        cur = max(cur , b[i+1]);
        best[i] = max(best[i+1], a[i] + cur);
        mxA[i] = max(mxA[i+1], a[i]);
    }
    cur = -1e17;
    for (int i=mid+1;i<=e;i++){
        cur = max(cur, a[i-1]);
        best[i] = max(best[i-1], b[i]+cur);
        mxB[i] = max(mxB[i-1], b[i]);
    }
    for (auto q:Q){
        if (r[q]<mid)L.push_back(q);
        else if (l[q]>mid)R.push_back(q);
        else {
            ret[q] = max(best[r[q]],best[l[q]]);
            ret[q] = max(ret[q], mxA[l[q]]+mxB[r[q]]);
        }
    }
    solve(s,mid-1,L);
    solve(mid+1,e,R);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>d[i];
    for (int i=1;i<=n;i++)
        cin>>h[i], h[i]*=2;
    for (int i=1;i<=n;i++) d[i+n] = d[i], h[i+n]=h[i];
    for (int i=1;i<=2*n;i++){
        loc[i] = loc[i-1]+d[i-1];
        a[i] = h[i] - loc[i];
        b[i] = h[i] + loc[i];
    }
    vector<int> Q;
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        if (x>y) l[i]=y+1, r[i] = x-1;
        else {
            l[i] = y+1;
            r[i] = x+n-1;
        }
        Q.push_back(i);
    }
    solve(1,2*n,Q);
    for (int i=1;i<=m;i++)cout<<ret[i]<<endl;
}