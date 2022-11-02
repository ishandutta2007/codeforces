#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll>pii;
#define ff first
#define ss second
#define pb push_back
ll arr[1010101];
ll ne[2][1010101];
ll vis[1010101];

vector<ll> v1;
vector<ll> v2;
ll nn;

void dfs(ll x,ll y){
    //printf("%lld\n",x);
    vis[x]=1;
    ll i=x;
    if(ne[0][i]%nn==y%nn){
        v2.pb(ne[0][i]);
        v1.pb(ne[1][i]);
        ll nxt;
        if(ne[1][i]<=nn) nxt=ne[1][i]+nn;
        else nxt=ne[1][i]-nn;
        //printf("%lld %lld\n",ne[1][i],nxt);
        if(!vis[arr[nxt]]){
            dfs(arr[nxt],ne[1][i]);
        }
    }
    else{
        v2.pb(ne[1][i]);
        v1.pb(ne[0][i]);
        ll nxt;
        if(ne[0][i]<=nn) nxt=ne[0][i]+nn;
        else nxt=ne[0][i]-nn;
        //printf("%lld %lld\n",ne[0][i],nxt);
        if(!vis[arr[nxt]]){
            dfs(arr[nxt],ne[0][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,l,m,n;
    cin>>n;
    n*=2;
    nn=n/2;
    if(n%4==0){
        cout<<"First"<<endl;
        for(i=1;i<=n;i++){
            cout<<i%(n/2)+1<<' ';
        }
        cout<<'\n';
       // cin>>n;
        return 0;
    }
    cout<<"Second"<<endl;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        if(ne[0][arr[i]]==0) ne[0][arr[i]]=i;
        else ne[1][arr[i]]=i;
    }

    for(i=1;i<=n/2;i++){
        if(!vis[i]) dfs(i,ne[0][i]);
    }




    ll ans=0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(auto k:v1){
        ans+=k;
    }
    if(ans%n==0){
        for(auto k:v1){
            cout<<k<<' ';
        }
        cout<<endl;
    }
    else {
         for(auto k:v2){
            cout<<k<<' ';
        }
        cout<<endl;
    }
    //cin>>n;
    return 0;
}