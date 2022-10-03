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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    vector<ll> A={0,1,3,2};
    while(si(A)<32){
        vector<ll> B=A;
        reverse(all(B));
        for(ll x:B) A.push_back(x+si(B));
    }
    
    vector<vector<int>> S(32,vector<int>(32));
    
    for(int i=0;i<32;i++){
        int x=0;
        for(int t=0;t<=4;t++){
            if(A[i]&(1<<t)) x^=(1<<(2*t+1));
        }
        for(int j=0;j<32;j++){
            S[i][j]^=x;
        }
    }
    
    for(int j=0;j<32;j++){
        int x=0;
        for(int t=0;t<=4;t++){
            if(A[j]&(1<<t)) x^=(1<<(2*t));
        }
        for(int i=0;i<32;i++){
            S[i][j]^=x;
        }
    }
    
    vector<pair<int,int>> dic(1024);
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            dic[S[i][j]]=mp(i,j);
        }
    }
    
    int N,K;cin>>N>>K;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            cout<<(S[i][j]^S[i][j+1])<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            cout<<(S[i][j]^S[i+1][j])<<" ";
        }
        cout<<endl;
    }
    
    int now=0;
    
    while(K--){
        int x;cin>>x;
        now^=x;
        cout<<dic[now].fi+1<<" "<<dic[now].se+1<<endl;
    }
}