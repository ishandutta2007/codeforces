

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
    int n,a,b;cin>>n>>a>>b;
    int x=-100,y=-100;
    for(int Y=0;Y<=n/b+1;Y++){
        int X=(n-b*Y)/a;
        if(a*X+b*Y==n&&X>=0&&Y>=0){
            x=X;
            y=Y;
            break;
        }
    }
    if(x<0||y<0){
        cout<<-1<<endl;
        return 0;
    }
    vector<int>ans;
    int pos=a;
    for(int i=1;i<=x;i++){
        ans.push_back(pos);
        for(int j=pos-a+1;j<=pos-1;j++){
            ans.push_back(j);
        }
        pos+=a;
    }
    pos+=b-a;
    for(int i=1;i<=y;i++){
        ans.push_back(pos);
        for(int j=pos-b+1;j<=pos-1;j++){
            ans.push_back(j);
        }
        pos+=b;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }cout<<endl;
    
    
    return 0;
}