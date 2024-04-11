

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
int mod(ll a){
    int c=a%1000000007;
    if(c>=0)return c;
    else return c+1000000007;
}
typedef pair<int,int> i_i;
#define inf 100000000/*10^8*/

/////////////////////////////////
/*int n,m;cin>>n>>m;
int kila[n];for(int i=0;i<=n-1;i++)cin>>kila[i];
int kilb[m];for(int i=0;i<=m-1;i++)cin>>kilb[i];*/


int main(){
    int n,k;cin>>n>>k;
    int ans=1000000;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        if(k%t==0){
            if(ans>k/t)ans=k/t;
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}