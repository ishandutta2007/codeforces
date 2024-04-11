
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
    char room[n+1][m+2];
    for(int i=0;i<=n-1;i++)cin>>room[i];
    int a[n+1][m+1];memset(a,0,sizeof(a));
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(room[i-1][j-1]=='*')a[i][j]=0;
            else a[i][j]=a[i][j-1]+1;
            if(a[i][j]>=k)ans++;
        }
    }
    memset(a,0,sizeof(a));
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(room[i-1][j-1]=='*')a[i][j]=0;
            else a[i][j]=a[i-1][j]+1;
            if(a[i][j]>=k)ans++;
        }
    }
    if(k==1){
        ans=0;
        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=m-1;j++){
                if(room[i][j]=='.')ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}