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
    int n,k;cin>>n>>k;
    char s[n+1];cin>>s;
    int t[k+1];
    int sa=0;
    int left=0;
    int pos=0;
    rep(i,0,n-1){
        if(left<k/2&&s[i]=='('){
            t[pos]=1;
            pos++;
            left++;
            sa++;
        }else if(s[i]==')'&&sa>=1){
            t[pos]=2;
            pos++;
            sa--;
        }
        
        if(pos==k-1)break;
    }
    rep(i,0,k-1){
        if(t[i]==1)cout<<'(';
        else cout<<')';
    }
    cout<<endl;
    return 0;
}