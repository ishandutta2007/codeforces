#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
typedef pair<int, int>	pii;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;

const int mod = 1'000'000'007;
//=======================

// segment tree;

// func function will change;
ll func(ll a,ll b){
    return a+b;
}

// invalid_value function will change;
ll invalid_value(){
    return 0;
}

void buildtree(ll si,ll ss,ll se,vl &st,vl &arr,vl &lt,vl &ltmin){
    if(ss==se){
        st[si]=arr[ss];
        lt[si]=arr[ss];
        ltmin[si]=arr[ss];
        return;
    }
    ll mid=(ss+se)/2;

    buildtree(2*si,ss,mid,st,arr,lt,ltmin);
    buildtree(2*si+1,mid+1,se,st,arr,lt,ltmin);

    st[si]=func(st[2*si],st[2*si+1]);
    lt[si]=max(lt[2*si],st[2*si]+lt[2*si+1]);
    ltmin[si]=min(ltmin[2*si],st[2*si]+ltmin[2*si+1]);
}

ll query(ll si,ll ss,ll se,ll qs,ll qe,vl &st,vl &lt){
    if(qs>se || qe<ss) return 0;
    if(ss>=qs && se<=qe) return st[si];
    ll mid=(ss+se)/2;
    ll l=query(2*si,ss,mid,qs,qe,st,lt);
    ll r=query(2*si+1,mid+1,se,qs,qe,st,lt);
    return func(l,r);
}

ll query_max(ll si,ll ss,ll se,ll qs,ll qe,vl &st,vl &lt){
    if(qs>se || qe<ss) return INT32_MIN;
    if(ss>=qs && se<=qe) return lt[si];
    ll mid=(ss+se)/2;
    ll l=query_max(2*si,ss,mid,qs,qe,st,lt);
    ll r=query_max(2*si+1,mid+1,se,qs,qe,st,lt);
    return max(l,st[2*si]+r);
}

ll query_min(ll si,ll ss,ll se,ll qs,ll qe,vl &st,vl &ltmin){
    if(qs>se || qe<ss) return INT32_MAX;
    if(ss>=qs && se<=qe) return ltmin[si];
    ll mid=(ss+se)/2;
    ll l=query_min(2*si,ss,mid,qs,qe,st,ltmin);
    ll r=query_min(2*si+1,mid+1,se,qs,qe,st,ltmin);
    return min(l,st[2*si]+r);
}

// update function will change;
// point update;
void update(ll si,ll ss,ll se,ll qi,vl &st,vl &arr,vl &lt,vl &ltmin){
    if(ss==se){
        st[si]=arr[ss];
        lt[si]=arr[ss];
        ltmin[si]=arr[ss];
        return;
    }
    ll mid=(ss+se)/2;
    if(qi<=mid) update(2*si,ss,mid,qi,st,arr,lt,ltmin);
    else update(2*si+1,mid+1,se,qi,st,arr,lt,ltmin);

    st[si]=func(st[2*si],st[2*si+1]);
    lt[si]=max(lt[2*si],st[2*si]+lt[2*si+1]);
    ltmin[si]=min(ltmin[2*si],st[2*si]+ltmin[2*si+1]);
}

void solve() {
  ll i, j, n, m;
  cin>>n;
  string s;
  cin>>s;
  vl arr(n+1,0),st(4*n+4,0),lt(4*n+4,INT32_MIN),ltmin(4*n+4,INT32_MAX);
  // lt contains max sum of prefix;
//   rep(i,n){
//       if(s[i-1]=='(') arr[i]=1;
//       else if(s[i-1]==')') arr[i]=-1;
//       else arr[i]=0;
//   }
  buildtree(1,1,n,st,arr,lt,ltmin);
//   for(i=1;i<=31;i++) deb2(i,ltmin[i]);
//   cout<<"\n";
  ll curr=1ll,sz=curr,prev=0;
  for(i=0;i<n;i++){
      // 1 indexed hai bro;
      // if value of query non zero then -1 , else depth;
      // also check if any prefix is negative;
      if(s[i]=='R'){
        //   if(query(1,1,n,1,sz,st,lt)!=0 || query_min(1,1,n,1,sz,st,ltmin)<0){
        //       cout<<"-1 ";
        //   }
        //   else{
        //     //   deb(sz);
        //       cout<<query_max(1,1,n,1,sz,st,lt)<<" ";
        //   }
          cout<<prev<<" ";
          curr++;
          sz=max(curr,sz);
      }
      else if(s[i]=='L'){
        //   if(query(1,1,n,1,sz,st,lt)!=0 || query_min(1,1,n,1,sz,st,ltmin)<0){
        //       cout<<"-1 ";
        //   }
        //   else{
        //     //   deb(sz);
        //       cout<<query_max(1,1,n,1,sz,st,lt)<<" ";
        //   }
          cout<<prev<<" ";
          curr=max(1ll,curr-1);
          sz=max(curr,sz);
      }
      else{
          if(s[i]=='('){
              arr[curr]=1;
              update(1,1,n,curr,st,arr,lt,ltmin);
          }
          else if(s[i]==')'){
              arr[curr]=-1;
              update(1,1,n,curr,st,arr,lt,ltmin);
          }
          else{
              arr[curr]=0;
              update(1,1,n,curr,st,arr,lt,ltmin);
          }
          if(query(1,1,n,1,sz,st,lt)!=0 || query_min(1,1,n,1,sz,st,ltmin)<0){
              cout<<"-1 ";
              prev=-1;
          }
          else{
            //   deb(sz);
              prev=query_max(1,1,n,1,sz,st,lt);
              cout<<prev<<" ";
          }
      }
    //   deb2(curr,sz);
  }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
    return 0;
}