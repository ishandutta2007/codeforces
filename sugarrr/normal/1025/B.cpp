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
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


/////////////////////////////////////////////////////////////////


vector<ll>prime;
vector<ll>v;

void pri(ll x){
    for(ll y:prime){
        if(x%y==0){
            v.push_back(y);
        }
        while(x%y==0){
            x=x/y;
        }
    }
    v.push_back(x);
}

int main(){
    ll n;cin>>n;
    ll a[n][2];rep(i,0,n-1)cin>>a[i][0]>>a[i][1];
    if(n==1){
        cout<<a[0][0]<<endl;
        return 0;
    }
    int N=50000;
    bool d[N];memset(d,true,sizeof(d));
    d[1]=false;d[0]=false;
    rep(i,2,N-1){
        if(d[i]==true){
            ll j=i*2;
            while(j<=N-1){
                d[j]=false;
                j+=i;
            }
        }
    }
    rep(i,2,N-1)if(d[i]==true)prime.push_back(i);
    
    pri(a[0][0]);
    pri(a[0][1]);
    v.push_back(a[0][0]);
    v.push_back(a[0][1]);
/*       for(auto y:v){
     cout<<y<<endl;
     }
    cout<<endl;*/
    for(ll x:v){
        if(x<2)continue;
        bool flag=true;
        rep(i,1,n-1){
            if(a[i][0]%x==0||a[i][1]%x==0){
            }else{
                flag=false;
                break;
            }
        }
        if(x>=2&&flag){
            cout<<x<<endl;
            return 0;
        }
    }
    
    cout<<-1<<endl;
    return 0;
}