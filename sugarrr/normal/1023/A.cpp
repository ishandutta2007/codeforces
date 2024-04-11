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
void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    bool flag=false;
    int num=-1;
    rep(i,0,n-1){
        if(s[i]=='*'){flag=true;num=i;}
    }
    if(flag){
        if(n>m+1)no();
        else{
            bool ans=true;
            rep(i,0,num-1){
                if(s[i]!=t[i])ans=false;
            }
            rep(i,num+1,n-1){
                if(s[i]!=t[i+m-n])ans=false;
            }
            if(ans)yes();
            else no();
        }
    }else{
        if(n==m&&s==t)yes();
        else no();
    }
    
    
    return 0;
}