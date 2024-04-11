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
const int mod=998244353,MAX=55,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),B(N),Ama(N+1),Bma(N+1),Ama2(N),Bma2(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            Ama[i]=A[i]+N-i;
            Ama2[i]=A[i]+i+1;
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
            Bma[i]=B[i]+N-i;
            Bma2[i]=B[i]+i+1;
        }
        for(int i=N-2;i>=0;i--){
            chmax(Ama[i],Ama[i+1]);
            chmax(Bma[i],Bma[i+1]);
            chmax(Ama2[i],Ama2[i+1]);
            chmax(Bma2[i],Bma2[i+1]);
        }
        Ama.back()=-INF;
        Ama.back()=-INF;
        int ans=INF,X=0;
        
        for(int i=0;i<N;i++){
            if(i%2==0){
                chmin(ans,max({X+2*(N-i)-1,Ama[i+1]+(N-i),Bma2[i]-i}));
                X++;
                chmax(X,B[i]+1);
                X++;
                if(i+1<N) chmax(X,B[i+1]+1);
            }else{
                chmin(ans,max({X+2*(N-i)-1,Bma[i+1]+(N-i),Ama2[i]-i}));
                X++;
                chmax(X,A[i]+1);
                X++;
                if(i+1<N) chmax(X,A[i+1]+1);
            }
        }
        
        cout<<ans<<"\n";
    }
}