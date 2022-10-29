

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


int main(){
    int n,m;cin>>n>>m;
    int a[n+1];memset(a,0,sizeof(a));
    rep(i,1,m){
        int k;cin>>k;a[k]++;
    }
    int min=inf;
    rep(i,1,n){
        if(a[i]<min)min=a[i];
    }
    cout<<min<<endl;
    
    return 0;
}