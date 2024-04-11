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
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll m;cin>>m;
    ll b[m];rep(i,0,m-1)cin>>b[i];
    rep(i,1,n-1){
        a[i]=a[i]+a[i-1];
    }
    rep(i,1,m-1){
        b[i]=b[i]+b[i-1];
    }
    if(a[n-1]!=b[m-1]){
        cout<<-1<<endl;
    }else{
        int apos=0,bpos=0;
        int c=0;
        while(apos<=n-1&&bpos<=m-1){
            if(a[apos]==b[bpos]){
                c++;
                apos++;
                bpos++;
            }else if(a[apos]>b[bpos]){
                bpos++;
            }else{
                apos++;
            }
        }
        cout<<c<<endl;
    }

    return 0;
    
}