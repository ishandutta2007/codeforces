/*
______     _   _                               _                
| ___ \   | | (_)                             | |               
| |_/ /___| |_ _ _ __ ___ _ __ ___   ___ _ __ | |_              
|    // _ \ __| | '__/ _ \ '_ ` _ \ / _ \ '_ \| __|             
| |\ \  __/ |_| | | |  __/ | | | | |  __/ | | | |_              
\_| \_\___|\__|_|_|  \___|_| |_| |_|\___|_| |_|\__|             
 
 
 _____      _   _       _      ___  _ _                       _ 
|_   _|    | \ | |     | |    / _ \| | |                     | |
  | | ___  |  \| | ___ | |_  / /_\ \ | | _____      _____  __| |
  | |/ __| | . ` |/ _ \| __| |  _  | | |/ _ \ \ /\ / / _ \/ _` |
 _| |\__ \ | |\  | (_) | |_  | | | | | | (_) \ V  V /  __/ (_| |
 \___/___/ \_| \_/\___/ \__| \_| |_/_|_|\___/ \_/\_/ \___|\__,_|
 
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int L[2000000];
int R[2000000];
ll tree[2000000];
vector<int> sw[20];
ll a[2000000];
int ls[2000000];
#define mid ((l+r)>>1)
void build(int x,int l,int r){
  if (l==r) tree[x] = a[l];
  else {
    L[x] = x*2;
    R[x] = x*2+1;
    build(L[x], l, mid);
    build(R[x], mid+1, r);
    tree[x] = tree[L[x]]+tree[R[x]];
  }
}
int T;
ll query(int x,int l, int r,int s,int e, int lev){
  if (l>e || r<s) return 0;
  if (l>=s && r<=e) return tree[x];
  if (sw[lev].size() && ls[x]!=sw[lev].back()){
      int num = sw[lev].end() - upper_bound(sw[lev].begin(),sw[lev].end(), ls[x]);
      num%=2;
      if (num) swap(L[x], R[x]);
      ls[x] = sw[lev].back();
    }
  return query(L[x], l, mid, s, e, lev+1) + query(R[x], mid+1,r,s,e,lev+1);
}
void upd(int x,int l, int r,int id, int val, int lev){
  if (id<l || id>r) return;
  if (l==r) tree[x] = val;
  else{
    if (sw[lev].size() && ls[x]!=sw[lev].back()){
      int num = sw[lev].end() - upper_bound(sw[lev].begin(),sw[lev].end(), ls[x]);
      num%=2;
      if (num) swap(L[x], R[x]);
      ls[x] = sw[lev].back();
    }
    if (id<=mid) upd(L[x], l, mid, id, val, lev+1);
    else upd(R[x], mid+1,r,id, val, lev+1);
    tree[x] = tree[L[x]]+tree[R[x]];
  }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin>>n>>q;
    int N = n;
    n = (1<<n);
    for (int i=0;i<n;i++){
      cin>>a[i];
    }
    build(1, 0, n-1);
    while(q--){
      T++;
      int t;
      cin>>t;
      if (t==1) {
        int x,k;
        cin>>x>>k;
        x--;
        upd(1, 0, n-1, x, k, 0);
      } else if (t==2){
        int k;
        cin>>k;
        k=N-k;
        for (int i=k;i<=N;i++) sw[i].push_back(T);
      } else if(t==3){
        int k;
        cin>>k;
        k = N-k-1;
        k=max(k, 0);
        sw[k].push_back(T);
      } else {
        int l, r;
        cin>>l>>r;
        l--,r--;
        cout<<query(1, 0, n-1, l, r, 0)<<endl;
      }
    }
}