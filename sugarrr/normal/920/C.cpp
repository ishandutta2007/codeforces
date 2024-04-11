
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
#define N 200005
int a[N];
int main(){
    int n;cin>>n;
    for(int i=0;i<=n-1;i++)cin>>a[i];
    char ssss[n+1];cin>>ssss;
    int s=inf;
    for(int i=0;i<=n-2;i++){
        if(ssss[i]=='1'){
            s=i;i++;
            while(ssss[i]=='1'){
                i++;
            }
            sort(a+s,a+i+1);
        }
    }
    bool ans=true;
    for(int i=0;i<=n-1;i++){
        if(i!=a[i]-1)ans=false;
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}