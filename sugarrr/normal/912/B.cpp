


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
    ll n,k;cin>>n>>k;
    ll a[65];
    a[0]=1;for(int i=1;i<=62;i++)a[i]=2*a[i-1];
    int c;
    for(c=0;c<=61;c++){
        if(n<a[c])break;
    }
    c--;
    ll ans=0;
    if(k>=2)ans=a[c+1]-1;
    else if(k==1)ans=n;
    cout<<ans<<endl;
    return 0;
}