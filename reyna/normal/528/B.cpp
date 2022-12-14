//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int Maxn = 1e6;
pair<int,int> pos[Maxn];
int w[Maxn],x[Maxn],place[Maxn];
pair<int,int> arr[Maxn];
int dp[Maxn];
int t[4 * Maxn],is_leaf[4 * Maxn],id[4 * Maxn];
int n;
void build(int v = 1,int b = 0,int e = n-1){
    if(b == e){
        is_leaf[v] = 1;
        id[b] = v;
        return;
    }
    int l = v << 1;
    int r = l | 1;
    int mid = b + e >> 1;
    build(l,b,mid);
    build(r,mid+1,e);
    return;
}
void update(int v,int val){
    if(!v)
        return;
    if(is_leaf[v]){
        t[v] = val;
    }
    int l = v << 1;
    int r = l | 1;
    if(!is_leaf[v])
        t[v] = max(t[l],t[r]);
    update(v >> 1,val);
    return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
    if(j < i)
        return 0;
    if(i > e || b > j)
        return 0;
    if(i <= b && e <= j)
        return t[v];
    int l = v << 1,r = l | 1,mid = b + e >> 1;
    return max(query(i,j,l,b,mid),query(i,j,r,mid+1,e));
}
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        scanf("%d%d",&x[i],&w[i]);
        pos[i] = make_pair(x[i] + w[i],i);
        arr[i] = make_pair(x[i],i);
    }
    build();
    sort(pos,pos+n);
    sort(arr,arr+n);
    for(int i = 0; i < n;i++){
        place[pos[i].second] = i;
    }
    for(int i = 0; i < n;i++){
        int ind = arr[i].second;
        int pl = upper_bound(pos,pos+n,make_pair(x[ind] - w[ind],Maxn)) - pos;
        int Max = query(0,pl-1);
//      cerr << pl << ' ' << place[ind]<< ' ' << x[ind] << ' ' << w[ind]<< endl;
        ind = place[ind];
        dp[ind] = Max+1;
//      cerr << Max +1 << " HI " <<  ind << ' ' << 0 << ' ' << pl-1<< endl;
        update(id[ind],dp[ind]);
    }
    int ans = 0;
    for(int i = 0; i < n;i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
    
}