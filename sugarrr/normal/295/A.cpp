
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
    int n,m,k;cin>>n>>m>>k;
    ll  a[n+1];for(int i=0;i<=n-1;i++)cin>>a[i];
    ll task[m][3];
    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=2;j++)cin>>task[i][j];
    }
   ll imos[m+1];memset(imos,0,sizeof(imos));
    while(k--){
        ll s,t;cin>>s>>t;s--;t--;
        imos[s]++;imos[t+1]--;
    }
    for(int i=1;i<=m-1;i++)imos[i]+=imos[i-1];
    for(int i=0;i<=m-1;i++){
        task[i][2]*=imos[i];
    }
    ll imo[n+1];memset(imo,0,sizeof(imo));
    for(int i=0;i<=m-1;i++){
        ll s=task[i][0],t=task[i][1];s--;t--;
        imo[s]+=task[i][2];imo[t+1]-=task[i][2];
    }
    for(int i=1;i<=n-1;i++)imo[i]+=imo[i-1];
    
    for(int i=0;i<=n-1;i++){
        cout<<imo[i]+a[i]<<" ";
    }
    return 0;
}