
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

bool digit(int m){
    int a=0;
    while(m>0){
        a+=m%10;
        m/=10;
    }
    return a==10;
}

int main(){
    int n;cin>>n;
    int ans=1;int c=0;
    while(1){
        if(digit(ans))c++;
        if(c==n){
            cout<<ans<<endl;
            break;
        }
        ans++;
    }
    return 0;
}