

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
    int a[n][2];
    rep(i,0,n-1)cin>>a[i][0]>>a[i][1];
    
    bool flag=true;
    int high=max(a[0][0],a[0][1]);
    
  //  cout<<high<<endl;
    
    rep(i,1,n-1){
        if(a[i][0]<a[i][1])swap(a[i][0],a[i][1]);
        if(high<a[i][1]){
            flag=false;
        }else if(high<a[i][0]){
            high=a[i][1];
        }else{
            high=a[i][0];
        }
     //   cout<<high<<endl;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}