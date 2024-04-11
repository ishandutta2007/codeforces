
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
typedef pair<double,double>d_d;
#define inf 100000000//10^8

/////////////////////////////////


int main(){
    int qqq;cin>>qqq;
    while(qqq--){
        int n;cin>>n;
        i_i time[n];for(int i=0;i<=n-1;i++)cin>>time[i].first>>time[i].second;
        int ans[n],t=1;
        for(int i=0;i<=n-1;i++){
            if(t<=time[i].second){
                if(t>=time[i].first){
                ans[i]=t,t++;
                }else{
                    ans[i]=time[i].first;
                    t=time[i].first+1;
                }
            }else{
                ans[i]=0;
            }
        }
        for(int i=0;i<=n-1;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}