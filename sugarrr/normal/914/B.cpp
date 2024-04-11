


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


int a[100005];
int main(){
    int n;cin>>n;
    for(int i=0;i<=n-1;i++){
        int c;cin>>c;
        a[c]++;
    }
    bool flag=false;
    for(int i=1;i<=100000;i++){
        if(a[i]%2!=0)flag=true;
    }
    
    if(flag)cout<<"Conan"<<endl;
    else cout<<"Agasa"<<endl;
    
    return 0;
}