

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
#define inf 100000000/*10^8*/
#define rep(i,l,r) for(int i=l;i<=r;i++)
const double EPS=1E-8;

////////////////////////////////////////
bool prime[1000005];


int find(int n){
    int p=2;
    int res=1;
    while(p*p<=n){
        if(n%p==0){
            n/=p;
            res=p;
        }else{
            p++;
            while(!prime[p])p++;
        }
    }
    if(prime[n])res=max(res,n);
    return res;
}


int main() {
    int x2;cin>>x2;
    memset(prime,true,sizeof(prime));
    for(int i=2;i<=1000;i++){
        if(prime[i]){
            for(int j=2;i*j<=1000000;j++){
                prime[i*j]=false;
            }
        }
    }
    int p2=find(x2);
    int ans=inf;
    for(int x1=x2-p2+1;x1<=x2;x1++){
        int z=x1-find(x1)+1;
       if(z>=3) ans=min(ans,z);
    }
    cout<<ans<<endl;
    return 0;
}