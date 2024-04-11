

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
int min(int a,int b){
    if(a<b)return a;else return b;
}
int abs(int a){
    if(a>0)return a;
    else return a*(-1);
}

int main(){
    int n,pos,l,r;cin>>n>>pos>>l>>r;
    int ans=0;
    if(l!=1&&r!=n){
        if(l<=pos&&pos<=r){
            ans=r-l+min(pos-l,r-pos)+2;
        }else if(pos<l){
            ans=r-pos+2;
        }else{
            ans=pos-l+2;
        }
    }else if(l==1&&r!=n){
        ans=abs(r-pos)+1;
    }else if(r==n&&l!=1){
        ans=abs(pos-l)+1;
    }else{
        ans=0;
    }
    cout<<ans<<endl;
    return 0;
}