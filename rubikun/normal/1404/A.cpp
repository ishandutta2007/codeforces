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
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        string S;cin>>S;
        
        vector<int> A(K),B(K),C(K);
        
        for(int i=0;i<N;i++){
            if(S[i]=='0') A[i%K]=1;
            else if(S[i]=='1') B[i%K]=1;
            else C[i%K]=1;
        }
        
        bool ok=true;
        
        for(int i=0;i<K;i++){
            if(A[i]&&B[i]) ok=false;
            if(A[i]){
                for(int j=i;j<N;j+=K) S[j]='0';
                C[i]=0;
            }
            if(B[i]){
                for(int j=i;j<N;j+=K) S[j]='1';
                C[i]=0;
            }
        }
        
        int cnt0=0,cnt1=0;
        for(int i=0;i<K;i++){
            if(S[i]=='0') cnt0++;
            if(S[i]=='1') cnt1++;
        }
        
        if(cnt0>K/2||cnt1>K/2) ok=false;
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}