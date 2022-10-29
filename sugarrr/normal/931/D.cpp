

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


int main() {
    int n;cin>>n;
    int c[n+2];memset(c,0,sizeof(c));
    int p[n+2];rep(i,2,n)cin>>p[i];
    int d[n+2];
    d[1]=0;c[0]++;
    rep(i,2,n){
        int D=d[p[i]]+1;
        d[i]=D;
        c[D]++;
    }
    int ans=0;
    rep(i,0,n+1)if(c[i]%2==1)ans++;
    cout<<ans<<endl;
    
    return 0;
}