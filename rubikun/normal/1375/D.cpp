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
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        vector<int> ans;
        
        while(1){
            bool ok=true;
            for(int i=0;i<N;i++){
                if(A[i]!=i) ok=false;
            }
            if(ok) break;
            
            set<int> SE;
            for(int i=0;i<N;i++){
                SE.insert(A[i]);
            }
            for(int i=0;i<=N;i++){
                if(SE.count(i)==0){
                    if(i<N){
                        A[i]=i;
                        ans.push_back(i+1);
                    }else{
                        for(int j=N-1;j>=0;j--){
                            if(A[j]!=j){
                                A[j]=i;
                                ans.push_back(j+1);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
        
        cout<<si(ans)<<"\n";
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
        
    }
}