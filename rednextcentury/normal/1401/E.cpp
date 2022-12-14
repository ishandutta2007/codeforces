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
struct event{
    int type; // 0: start vert line
              // 1: horizontal query
              // 2: end vert line
    int height;
    int l, r;
    event(int h, int t,int L,int R){
      type = t;
      height = h;
      l = L;
      r = R;
    }
};
bool operator <(event a, event b){
  if (a.height == b.height) return a.type<b.type;
  return a.height<b.height;
}
#define L (x<<1)
#define R (L+1)
#define mid ((l+r)>>1)
int tree[4100000];
void upd(int x,int l,int r,int id, int val){
  if (id<l || id>r) return;
  if (l==r) tree[x] += val;
  else {
    if (id<=mid) upd(L,l,mid,id,val);
    else upd(R,mid+1,r,id, val);
    tree[x] = tree[L]+tree[R];
  }
}
int query(int x,int l,int r,int s,int e){
  if (l>e || r<s)return 0;
  if (l>=s && r<=e) return tree[x];
  return query(L,l,mid,s,e)+query(R,mid+1,r,s,e);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<event> events;
    for (int i=0;i<n;i++){
        int h,l,r;
        cin>>h>>l>>r;
        events.push_back(event(h, 1, l, r));
    }
    ll ret=1;
    int mx = 1e6;
    for (int i=0;i<m;i++){
        int x,l,r;
        cin>>x>>l>>r;
        if (l==0 && r==mx) upd(1,0,mx, x, 1) , ret++;
        else if (l==0) {
          upd(1,0,mx, x, 1);
          events.push_back(event(r, 2, x,x));
        } else {
          events.push_back(event(l, 0, x,x));
        }
    }
    upd(1,0,mx,0, 1);
    upd(1, 0, mx, mx, 1);
    sort(events.begin(),events.end());
    for (auto e:events){
      if (e.type == 0){
        upd(1,0,mx,e.l, 1);
      } else if (e.type == 2){
        upd(1,0,mx,e.l, -1);
      } else {
        int x = query(1, 0 , mx, e.l, e.r);
        if (x>0) ret+=x-1;
      }
    }
    cout<<ret<<endl;
}