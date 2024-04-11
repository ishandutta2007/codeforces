
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


int main(){
    double n,m;cin>>n>>m;
    double max=0;
    for(int i=1;i<=n;i++){
        double a,b;cin>>a>>b;double c=b/a;
        if(max<c)max=c;
    }
    printf("%9.9lf\n",m/max);
    
    return 0;
}