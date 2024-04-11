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
const int mod=998244353,MAX=300005,INF=1000000000;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        vector<int> A(N);
        vector<pair<int,int>> B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            B[i]=mp(A[i],i);
        }
        if(N==K){
            cout<<INF<<"\n";
            continue;
        }
        sort(all(B));
        vector<int> use;
        for(int i=0;i<K;i++) use.push_back(B[i].se);
        sort(all(use));
        
        bool f=false;
        for(int i=0;i+1<si(use);i++) if(use[i]+1==use[i+1]) f=true;
        
        if(f){
            cout<<min(B[K].fi*2,INF)<<"\n";
            continue;
        }else{
            int ans=-1;
            if(K==1){
                chmax(ans,min(2*B[0].fi,B[N-1].fi));
                A[use[0]]=INF;
                for(int i=0;i+1<N;i++){
                    chmax(ans,min(2*B[K].fi,min(A[i],A[i+1])));
                }
            }else{
                chmax(ans,min(2*B[K-1].fi,INF));
                for(int a:use) A[a]=INF;
                for(int i=0;i+1<N;i++){
                    chmax(ans,min(2*B[K].fi,min(A[i],A[i+1])));
                }
                //chmax(ans,min(2*B[K].fi,B[K].fi));
            }
            
            cout<<ans<<"\n";
        }
    }
}