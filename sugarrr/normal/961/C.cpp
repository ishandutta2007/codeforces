

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
#define rep(i,l,r) for(int i=l;i<=r;i++)
const double EPS=1E-8;

////////////////////////////////////////


int main(){
    int n;cin>>n;
    char l[n+1][n+1],r[n+1][n+1];
    rep(i,0,n-1){
        rep(j,0,n-1){
            if((i+j)%2==0)r[i][j]='1';
            else r[i][j]='0';
            /*
            if((i+j)%2==0)l[i][j]='0';
            else l[i][j]='1';*/
        }
    }
    char s[4][n+1][n+1];
    rep(k,0,3){
        rep(i,0,n-1){
            cin>>s[k][i];
        }
    }
    int dif[4];
    rep(k,0,3){
        int count=0;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(s[k][i][j]!=r[i][j])count++;
            }
        }
        dif[k]=count;
    }
    sort(dif,dif+4);
    ll ans=dif[0]+dif[1]+n*n-dif[2]+n*n-dif[3];
    cout<<ans<<endl;
    
    return 0;
}