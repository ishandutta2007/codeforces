#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<int>> A(2,vector<int>(N)),B=A;
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>>B[i][j];
            if(j) B[i][j]+=B[i][j-1];
        }
    }
    
    ll ans=0,a=0,b=0;
    
    for(int j=0;j<N;j++){
        a+=A[0][j];
        b+=A[1][j];
        if(a>B[0][j]&&B[1][j]>b){
            ll x=min(a-B[0][j],B[1][j]-b);
            ans+=x;
            a-=x;
            b+=x;
        }
        if(a<B[0][j]&&B[1][j]<b){
            ll x=min(B[0][j]-a,b-B[1][j]);
            ans+=x;
            a+=x;
            b-=x;
        }
        ans+=abs(a-B[0][j]);
        ans+=abs(b-B[1][j]);
    }
    
    if(a!=B[0].back()||b!=B[1].back()){
        cout<<-1<<endl;
        return 0;
    }
    
    cout<<ans<<endl;
}