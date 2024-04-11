#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

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
   // ios::sync_with_stdio(false);
   // cin.tie(0);
    
    ll q;cin>>q;
    while(q--){
        ll n,m,k;cin>>n>>m>>k;
        if((n+m)%2==0){
            ll s=max(n,m);
            if(k<s){
                cout<<-1<<endl;
            }else if((k-s)%2==0){
                cout<<k<<endl;
            }else{
                cout<<k-2<<endl;
            }
        }else{
            ll s=max(n,m);
            if(k<s){
                cout<<-1<<endl;
            }else{
                cout<<k-1<<endl;
            }
        }
    }
    return 0;
    
}