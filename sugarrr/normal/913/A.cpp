

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
using namespace std;
typedef long long ll;
int mod(ll a){
    int c=a%1000000007;
    if(c>=0)return c;
    else return c+1000000007;
}
typedef pair<int,int> i_i;

int main(){
    int n,m;cin>>n>>m;
    int nn=1;
    for(int i=1;i<=n;i++){
        nn*=2;
        if(nn>=100000005)break;
    }
    if(nn>=100000005)cout<<m<<endl;
    else cout<<(m%nn)<<endl;
    
    return 0;
}