


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

int prime=100003;

int abs(int i,int j){
    if(i>j)return i-j;
    else return j-i;
}

int main(){
    int  n,k;cin>>n>>k;
    cout<<prime<<" "<<prime<<endl;
    for(int i=1;i<=n-2;i++){
        cout<<i<<" "<<i+1<<" 1"<<endl;
    }
    cout<<n-1<<" "<<n<<" "<<prime-(n-2)<<endl;
    int count=n-1;
    int i=1;
    int j=3;
    while(count<k){
        cout<<i<<" "<<j<<" "<<inf<<endl;
        count++;
        j++;
        while(abs(j-i)<=1)j++;
        if(j>n)i++,j=i+2;
        while(abs(j-i)<=1)j++;
    }
    
    return 0;
}