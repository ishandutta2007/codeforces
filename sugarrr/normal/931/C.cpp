

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

int MIN(int a,int b){
    if(a<b)return a;
    else return b;
}


int main() {
    int n;cin>>n;
    int a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    int c[3];memset(c,0,sizeof(c));
    int min=a[0];
    rep(i,0,n-1){
        c[a[i]-min]++;
    }
    if(c[1]==0&&c[2]==0){
        cout<<n<<endl;
        rep(i,0,n-1)cout<<min<<" ";
    }else if(c[1]==0){
        if(c[0]<c[2]){
            cout<<c[2]-c[0]<<endl;
            int m=c[2]-c[0];
            rep(i,1,m)cout<<min+2<<" ";
            rep(i,1,n-m)cout<<min+1<<" ";
        }else if(c[0]>c[2]){
            cout<<c[0]-c[2]<<endl;
            int m=c[0]-c[2];
            rep(i,1,m)cout<<min<<" ";
            rep(i,1,n-m)cout<<min+1<<" ";
        }else{
            cout<<0<<endl;
            rep(i,1,n)cout<<min+1<<" ";
        }
    }else if(c[2]==0){
        cout<<n<<endl;
        rep(i,0,n-1)cout<<a[i]<<" ";
    }else{
        int mi=inf;int miny=-1;
        for(int y=0;y<=n;y++){
            if((n-y+c[2]-c[0])%2!=0||n-y+c[2]-c[0]<0)continue;
            int z=(n-y+c[2]-c[0])/2;
            if((n-y+c[0]-c[2])%2!=0||n-y+c[0]-c[2]<0)continue;
            int x=(n-y+c[0]-c[2])/2;
            int q=MIN(x,c[0])+MIN(y,c[1])+MIN(z,c[2]);
            if(mi>q){
                mi=q;
                miny=y;
            }
        }
        if(mi==inf){
            cout<<n<<endl;
            rep(i,0,n-1)cout<<a[i]<<" ";
        }else{
            cout<<mi<<endl;
            int y=miny;
            int x=(n-y+c[0]-c[2])/2;
            int z=(n-y+c[2]-c[0])/2;
            rep(i,1,x)cout<<min<<" ";
            rep(i,1,y)cout<<min+1<<" ";
            rep(i,1,z)cout<<min+2<<" ";
        }
    }
    
    return 0;
}