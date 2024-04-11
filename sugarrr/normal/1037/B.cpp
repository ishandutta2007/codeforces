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
    ll n,s;cin>>n>>s;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    ll sum=0;
    ll m=n/2;
    if(a[m]==s){
        cout<<0<<endl;
    }else if(a[m]>s){
        rep(i,0,m){
            if(a[i]>s)sum+=a[i]-s;
        }
        cout<<sum<<endl;
    }else{
        rep(i,m,n-1){
            if(a[i]<s){
                sum+=s-a[i];
            }
        }
        cout<<sum<<endl;
    }
    
    return 0;
}