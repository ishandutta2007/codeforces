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


//////////////////////////////////////


int main(){
    int n,m,q;cin>>n>>m>>q;
    if(n<m){
        while(q--)cout<<0<<endl;
        return 0;
    }
    string s,t;cin>>s>>t;
    int res[n+1];res[0]=0;
    for(int i=0;i+m-1<=n-1;i++){
        bool flag=true;
        for(int j=0;j<=m-1;j++){
            if(s[i+j]!=t[j])flag=false;
        }
        if(flag)res[i+1]=res[i]+1;
        else res[i+1]=res[i];
    }
    
    while(q--){
        int a,b;cin>>a>>b;
        if(b-m+1<=a-1)cout<<0<<endl;
        else cout<<res[b-m+1]-res[a-1]<<endl;
    }
    
    
    return 0;
}