

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

int main(){
    ll p,k;cin>>p>>k;
    vector<ll> ans;
    bool flag=true;
    while(p!=0){
        if(flag){
            ans.push_back(p%k);
            p/=k;
            flag=false;
        }else{
            if(p%k==0)ans.push_back(0);
            else{ ans.push_back(k-p%k);
            p+=(k-p%k);
            }
            p/=k;
            flag=true;
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    
    return 0;
}