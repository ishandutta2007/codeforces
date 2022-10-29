

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

/////////////////////////////////


int main(){
    int n;cin>>n;
    ll ans=0;
    for(int c=n;c>=1;c--){
        for(int b=c;b>=1;b--){
            int a=b^c;
            if(a<=b&&a>=1&&c<a+b)ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}