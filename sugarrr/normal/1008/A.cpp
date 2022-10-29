

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
    string s;cin>>s;
    int len;len=s.size();
    int a[len];
    rep(i,0,len-1){
        if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'){
            a[i]=1;
        }else if(s[i]=='n'){
            a[i]=2;
        }else{
            a[i]=3;
        }
    }
    bool flag=true;
    rep(i,0,len-2){
        if(a[i]==3&&a[i+1]!=1)flag=false;
    }
    //check
    if(a[len-1]==3)flag=false;
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}