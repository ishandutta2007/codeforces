
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
typedef pair<double,double>d_d;
#define inf 100000000//10^8

/////////////////////////////////


int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int a[k];for(int i=0;i<=k-1;i++)cin>>a[i];
        sort(a,a+k);
        int ans=max(a[0],n-a[k-1]+1);
        for(int i=1;i<=k-1;i++){
            int tt=(a[i]-a[i-1]+2)/2;
            if(tt>ans)ans=tt;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}