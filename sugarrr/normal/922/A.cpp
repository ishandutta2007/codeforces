

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
    ll x,y;cin>>x>>y;
    bool flag;
    if(y==0)flag=false;
    else if(y==1){
        if(x==0)flag=true;
        else flag=false;
    }
    else if(x-(y-1)<0)flag=false;
    else if((x-(y-1))%2==0)flag=true;
    else flag=false;
    
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    
    return 0;
}