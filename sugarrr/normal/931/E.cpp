

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


int main() {
    char t[10005];
    cin>>t;
    int len=strlen(t);
    rep(i,len,2*len-1)t[i]=t[i-len];
    vector<int> s[30];
    rep(i,0,len-1){
        s[t[i]-'a'].push_back(i);
    }
    double ans=0;
    rep(i,0,26){
        int max=0;
         rep(j,1,len-1){
             int c=0;
             int q[30];
             memset(q,0,sizeof(q));
             for(int x:s[i]){
                 q[t[x+j]-'a']++;
                
             }
            rep(k,0,26)if(q[k]==1)c++;
             if(max<c)max=c;
         }
        ans+=max;
    }
    cout<<(double)ans/(double)len<<endl;
    return 0;
}