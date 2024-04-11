

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
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


//////////////////////////////////////


int main(){
    int n;cin>>n;
    int a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    int ans=0;
  /*  bool x[n],y[n];
    rep(i,0,n-1){x[i]=false;y[i]=false;}*/
    int xpos=0,ypos=0;
    while(ypos<=n-1&&a[xpos]>=a[ypos])ypos++;
    
    while(ypos<=n-1&&xpos<=n-1){
        if(a[ypos]>a[xpos]){
            ans++;
            xpos++;
            ypos++;
        }else{
            while(ypos<=n-1&&a[xpos]>=a[ypos])ypos++;
        }
    }
    cout<<ans<<endl;
    return 0;
}