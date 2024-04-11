


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
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/

/////////////////////////////////

bool check (int m){
    if(m<0)return true;
    else{
        bool flag=true;
        for(int i=0;i<=sqrt(m)+1;i++){
            if(m==i*i)flag=false;
        }
        return flag;
    }
}

int main(){
    int n;cin>>n;
   int a[n]; for(int i=0;i<=n-1;i++)cin>>a[i];
    sort(a,a+n);
    int k=n-1;
    while(1){
        if(check(a[k]))break;
        k--;
    }
    cout<<a[k]<<endl;
    
    
    return 0;
}