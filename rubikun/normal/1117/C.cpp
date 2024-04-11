#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    ll xdiff=x2-x1,ydiff=y2-y1;
    ll N;cin>>N;
    string S;cin>>S;
    ll left=0,right=INF;
    vector<ll> X(N+1,0),Y(N+1,0);
    for(int i=0;i<N;i++){
        X[i+1]=X[i];
        Y[i+1]=Y[i];
        if(S[i]=='U') Y[i+1]++;
        else if(S[i]=='D') Y[i+1]--;
        else if(S[i]=='L') X[i+1]--;
        else if(S[i]=='R') X[i+1]++;
    }
    
    ll xsum=0,ysum=0;
    xsum=INF/N*X[N]+X[INF%N];
    ysum=INF/N*Y[N]+Y[INF%N];
    ll a=xsum-xdiff,b=ysum-ydiff;
    if(abs(a)+abs(b)>INF) cout<<-1<<endl;
    else{
        while(right-left>1){
            ll mid=(left+right)/2;
            ll xsum=0,ysum=0;
            xsum=mid/N*X[N]+X[mid%N];
            ysum=mid/N*Y[N]+Y[mid%N];
            ll a=xsum-xdiff,b=ysum-ydiff;
            if(abs(a)+abs(b)<=mid){
                right=mid;
            }else left=mid;
        }
        cout<<right<<endl;
    }
}