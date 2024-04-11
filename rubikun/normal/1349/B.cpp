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
        vector<int> A(N);
        vector<int> where,ok;
        
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(A[i]==K) where.push_back(i);
            if(A[i]>=K) ok.push_back(i);
        }
        
        if(!si(where)){
            cout<<"no\n";
            continue;
        }
        
        bool ans=false;
        
        for(int i=0;i+1<si(ok);i++){
            if(ok[i+1]-ok[i]<=2) ans=true;
        }
        
        if(N==1) ans=true;
        
        if(ans) cout<<"yes\n";
        else cout<<"no\n";
        
    }
}