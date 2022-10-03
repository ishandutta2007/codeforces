#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200005,INF=1<<30;

vector<vector<int>> makeruirui(vector<vector<int>> &S){
    int H=S.size(),W=S[0].size();
    vector<vector<int>> T(H+1,vector<int>(W+1));
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            T[i][j]=S[i-1][j-1];
        }
    }
    for(int i=0;i<=H;i++){
        for(int j=1;j<=W;j++){
            T[i][j]+=T[i][j-1];
        }
    }
    for(int j=0;j<=W;j++){
        for(int i=1;i<=H;i++){
            T[i][j]+=T[i-1][j];
        }
    }
    return T;
}
ll H,W;
vector<vector<int>> T;

ll f(ll h,ll w){
    ll ans=0;
    ans+=(h/H)*(w/W)*T[H][W];
    ans+=(h/(2*H))*(H*(w%W));
    ans+=(w/(2*W))*(W*(h%H));
    
    if((h/H)%2&&w%W){
        ll hh=h/H-1,ww=w/W;
        int rev=0;
        rev+=__builtin_popcount(hh);
        rev+=__builtin_popcount(ww);
        rev%=2;
        if(rev==0){
            ans+=T[H][w%W];
        }else{
            ans+=(H)*(w%W)-T[H][w%W];
        }
    }
    
    if((w/W)%2&&h%H){
        ll hh=h/H,ww=w/W-1;
        int rev=0;
        rev+=__builtin_popcount(hh);
        rev+=__builtin_popcount(ww);
        rev%=2;
        if(rev==0){
            ans+=T[h%H][W];
        }else{
            ans+=(h%H)*(W)-T[h%H][W];
        }
    }
    
    if(h%H&&w%W){
        ll hh=h/H,ww=w/W;
        int rev=0;
        rev+=__builtin_popcount(hh);
        rev+=__builtin_popcount(ww);
        rev%=2;
        if(rev==0){
            ans+=T[h%H][w%W];
        }else{
            ans+=(h%H)*(w%W)-T[h%H][w%W];
        }
    }
    
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>H>>W>>Q;
    H*=2;
    W*=2;
    vector<vector<int>> S(H,vector<int>(W));
    for(int i=0;i<H/2;i++){
        for(int j=0;j<W/2;j++){
            char c;cin>>c;
            S[i][j]=int(c-'0');
            S[i+H/2][j+W/2]=S[i][j];
            S[i][j+W/2]=1-S[i][j];
            S[i+H/2][j]=1-S[i][j];
        }
    }
    
    T=makeruirui(S);
    
    while(Q--){
        ll h1,w1,h2,w2;cin>>h1>>w1>>h2>>w2;
        h1--;w1--;
        cout<<f(h2,w2)+f(h1,w1)-f(h1,w2)-f(h2,w1)<<"\n";
    }
}