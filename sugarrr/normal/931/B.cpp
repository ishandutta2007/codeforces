

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
    int n,a,b;cin>>n>>a>>b;a--;b--;
    int digit=-1;
    while(n>0){
        digit++;
        n/=2;
    }
    int i=1;
    for(i=1;i<=digit;i++){
        if(((a>>(digit-i))&1) != ((b>>(digit-i))&1))break;
    }
    if(i==1)cout<<"Final!"<<endl;
    else cout<<digit-i+1<<endl;
    return 0;
}