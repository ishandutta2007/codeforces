

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

////////////////////////////////////////

int main(){
    int n,m;cin>>n>>m;
    ll a[n],b[m];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<=m-1;i++){
        cin>>b[i];
    }
    ll ans2=1000000000000000001;
    for(int i=0;i<=n-1;i++){
        ll max=-1000000000000000001;
        for(int j=0;j<=n-1;j++){
            if(i==j)continue;
            for(int k=0;k<=m-1;k++){
                if(max<a[j]*b[k])max=a[j]*b[k];
            }
        }
        if(ans2>max)ans2=max;
    }
    cout<<ans2<<endl;
    return 0;
}