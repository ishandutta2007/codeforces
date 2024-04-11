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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A,B;
        vector<ll> AA(N),BB(N);
        for(int i=0;i<N;i++) cin>>AA[i];
        for(int i=0;i<N;i++) cin>>BB[i];
        for(int i=0;i<N;i++){
            int a,b;a=AA[i];b=BB[i];
            if(a==0) A.push_back(b);
            else B.push_back(b);
        }
        
        sort(all(A));
        sort(all(B));
        
        if(si(A)>si(B)) swap(A,B);
        
        ll ans=0;
        
        if(si(A)==si(B)){
            {
                vector<ll> S;
                S.push_back(A[0]);
                for(int i=si(B)-1;i>=0;i--){
                    S.push_back(B[i]);
                    S.push_back(A[i]);
                }
                S.pop_back();
                ll sum=0;
                for(int i=0;i<N;i++){
                    if(i) sum+=S[i]*2;
                    else sum+=S[i];
                }
                chmax(ans,sum);
            }
            swap(A,B);
            {
                vector<ll> S;
                S.push_back(A[0]);
                for(int i=si(B)-1;i>=0;i--){
                    S.push_back(B[i]);
                    S.push_back(A[i]);
                }
                S.pop_back();
                ll sum=0;
                for(int i=0;i<N;i++){
                    if(i) sum+=S[i]*2;
                    else sum+=S[i];
                }
                chmax(ans,sum);
            }
        }else{
            vector<ll> S;
            S.push_back(B[0]);
            ans+=B[0];
            for(int i=0;i<si(A);i++){
                S.push_back(A[si(A)-1-i]);
                S.push_back(B[si(B)-1-i]);
                
                ans+=A[si(A)-1-i]*2;
                ans+=B[si(B)-1-i]*2;
            }
            
            int i=1;
            while(si(S)<N){
                ans+=B[i];
                S.push_back(B[i]);
                i++;
            }
            
        }
        
        cout<<ans<<"\n";
    }
}