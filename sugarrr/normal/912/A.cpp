


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
using namespace std;
typedef long long ll;
int mod(ll a){return a%1000000007;};



int main(){
    ll y,b;cin>>y>>b;
    ll c,d,e;cin>>c>>d>>e;
    ll yy=0,bb=0;
    yy=2*c+d;
    bb=d+3*e;
    ll ans=0;
    if(yy>y)ans+=yy-y;
    if(bb>b)ans+=bb-b;
    cout<<ans<<endl;
    return 0;
}