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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        sort(all(A));
        sort(all(B));
        int ans=0;
        
        for(int q=29;q>=0;q--){
            ans|=(1<<q);
            map<int,int> MA,MB;
            for(int i=0;i<N;i++){
                int X=0;
                for(int j=0;j<30;j++){
                    if(ans&(1<<j)){
                        if(A[i]&(1<<j)){
                            
                        }else{
                            X|=(1<<j);
                        }
                    }
                }
                MA[X]++;
            }
            for(int i=0;i<N;i++){
                int X=0;
                for(int j=0;j<30;j++){
                    if(ans&(1<<j)){
                        if(B[i]&(1<<j)){
                            X|=(1<<j);
                        }else{
                            
                        }
                    }
                }
                MB[X]++;
            }
            bool ok=true;
            for(auto [a,b]:MA){
                if(MB.count(a)&&MB[a]==b){
                    
                }else{
                    ok=false;
                    break;
                }
            }
            
            if(!ok) ans^=(1<<q);
        }
        
        cout<<ans<<"\n";
    }
}