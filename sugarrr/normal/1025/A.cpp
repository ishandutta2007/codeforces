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

int main(){
    int n;cin>>n;
    string s;cin>>s;
    if(n==1){
        cout<<"Yes"<<endl;
        return 0;
    }else{
        int count[30];memset(count,0,sizeof(count));
        rep(i,0,n-1){
            count[s[i]-'a']++;
        }
        bool flag=false;
        rep(i,0,25){
            if(count[i]>=2)flag=true;
        }
        
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}