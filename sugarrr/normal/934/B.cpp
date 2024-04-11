

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
    ll k;cin>>k;
    if(k>=37)cout<<-1<<endl;
    else{
        while(k>=2){
            cout<<8;
            k-=2;
        }
        if(k==1)cout<<4;
        cout<<endl;
    }
    
    
    
    return 0;
}