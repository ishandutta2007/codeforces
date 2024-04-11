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
    ll n;cin>>n;
    string a,b;cin>>a>>b;
    /*bool c[n];
    rep(i,0,n-1){
        if(a[i]==b[i])c[i]=true;
        else c[i]=false;
    }*/
    ll ans=0;
    ll pos=0;
    while(pos<=n-1){
        if(a[pos]!=b[pos]){
            if(pos==n-1){
                ans++;
                pos++;
            }else{
                if(a[pos+1]!=b[pos+1]&&a[pos]!=a[pos+1]){
                    ans++;
                    pos+=2;
                }else{
                    ans++;
                    pos++;
                }
            }
        }else{
            pos++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}