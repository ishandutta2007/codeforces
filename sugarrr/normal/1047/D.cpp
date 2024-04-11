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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////


int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    ll n,m;cin>>n>>m;
    if(n>m)swap(n,m);
    if(n==1){
        ll a=m/3,b=(m+1)/3,c=(m+2)/3;
        ll minus=0;
        if(a%2==1)minus++;
        if(b%2==1)minus++;
        if(c%2==1)minus++;
        cout<<m-minus<<endl;
    }else if(n==2){
        if(m==2){
            cout<<0<<endl;
        }else if(m==3||m==7){
            cout<<n*m-2<<endl;
        }else{
            cout<<n*m<<endl;
        }
    }else if(n%2==0||m%2==0){
        cout<<n*m<<endl;
    }else{
        cout<<n*m-1<<endl;
    }
    
    
    return 0;
}