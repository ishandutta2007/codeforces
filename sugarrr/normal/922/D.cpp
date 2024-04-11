

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



////////////////////////////////////////

bool asc(const l_l a,const l_l b){
    return (a.first*b.second-a.second*b.first)>0;
}


int main(){
    int n;cin>>n;
    l_l num[n];
    ll ans=0;
    for(int i=0;i<=n-1;i++){
        string s;cin>>s;
        int len=s.size();
        int ns=0,nh=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='s')ns++;
            else nh++;
        }
        int cs=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='s')cs++;
            else ans+=cs;
        }
        num[i].first=ns;
        num[i].second=nh;
    }
    sort(num,num+n,asc);
    l_l sum[n];sum[0]=num[0];
    for(int i=1;i<=n-1;i++){
        sum[i].first=sum[i-1].first+num[i].first;
        sum[i].second=sum[i-1].second+num[i].second;
    }
    for(int i=0;i<=n-2;i++){
        ans+=num[i].first*(sum[n-1].second-sum[i].second);
    }
    
    cout<<ans<<endl;
    
    return 0;
}