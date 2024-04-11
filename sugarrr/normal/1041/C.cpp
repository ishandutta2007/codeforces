#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll n,m,d;cin>>n>>m>>d;
    priority_queue<l_l, vector<l_l>, greater<l_l> > que;
    rep(i,0,n-1){
        ll t;cin>>t;
        que.push(l_l(t,i));
    }
    priority_queue<l_l, vector<l_l>, greater<l_l> > p;
    ll ans[n];
    ll day=2;
    
    l_l top=que.top();
    ans[top.second]=1;
    que.pop();
    p.push(top);
    rep(i,1,n-1){
        l_l ptop=p.top();
        l_l qtop=que.top();que.pop();
        if(qtop.first<=ptop.first+d){
            ans[qtop.second]=day;
            day++;
            p.push(qtop);
        }else{
            ans[qtop.second]=ans[ptop.second];
            p.pop();
            p.push(qtop);
        }
    }
  /*  while(!p.empty()){
        l_l t=p.top();p.pop();
        cout<<t.first<<" "<<t.second<<endl;
    }*/
    
    ll ansd=0;
    rep(i,0,n-1)ansd=max(ansd,ans[i]);
    cout<<ansd<<endl;
    rep(i,0,n-1)cout<<ans[i]<<" ";
    cout<<endl;
    
    return 0;
}