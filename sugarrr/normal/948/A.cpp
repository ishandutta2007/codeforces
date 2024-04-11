

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
#define rep(i,l,r) for(int i=l;i<=r;i++)
const double EPS=1E-8;

////////////////////////////////////////



int main() {
    int h,w;cin>>h>>w;
    char m[h][w+1];
    rep(i,0,h-1)cin>>m[i];
    rep(i,0,h-1)rep(j,0,w-1){
        if(m[i][j]=='.')m[i][j]='D';
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool flag=true;
    rep(i,0,h-1)rep(j,0,w-1){
        if(m[i][j]=='S'){
            rep(k,0,3){
                int x=dx[k]+i;int y=dy[k]+j;
                if(0<=x&&x<=h-1&&0<=y&&y<=w-1){
                    if(m[x][y]=='W'){
                        flag=false;
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
        rep(i,0,h-1){
            cout<<m[i]<<endl;
        }
    }else{
        cout<<"No"<<endl;
    }
    
    return 0;
}