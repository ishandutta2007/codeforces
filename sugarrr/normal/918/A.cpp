
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
    int fib[30];
    fib[0]=1;fib[1]=1;
    for(int i=2;i<=29;i++)fib[i]=fib[i-1]+fib[i-2];
    char ans[1005];
    for(int i=0;i<=1004;i++)ans[i]='o';
    for(int i=1;i<=29;i++)if(fib[i]<=1002)ans[fib[i]]='O';
    int n;cin>>n;
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<endl;
    
    
    return 0;
}