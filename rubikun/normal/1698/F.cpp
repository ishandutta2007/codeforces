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
const int mod=998244353,MAX=2005,INF=1<<29;

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
        vector<pair<int,int>> ans;
        bool ok=true;
        
        for(int s=0;s<N;s++){
            if(A[s]!=B[s]){
                ok=false;
                break;
            }
            if(s==N-1) break;
            if(A[s+1]==B[s+1]) continue;
            
            for(int i=s+1;i+1<N;i++){
                if(A[i]==B[s+1]&&A[i+1]==A[s]){
                    ans.push_back(mp(s,i+1));
                    reverse(A.begin()+s,A.begin()+i+1+1);
                    break;
                }
            }
            
            if(A[s+1]==B[s+1]) continue;
            
            bool done=false;
            for(int i=s+1;i+1<N;i++){
                if(A[i]==A[s]&&A[i+1]==B[s+1]){
                    for(int l=s;l<=i;l++){
                        for(int r=i+1;r<N;r++){
                            if(A[l]==A[r]){
                                ans.push_back(mp(l,r));
                                reverse(A.begin()+l,A.begin()+r+1);
                                done=true;
                                break;
                            }
                        }
                        if(done) break;
                    }
                    if(done) break;
                }
            }
            
            if(!done){
                ok=false;
                break;
            }
            
            for(int i=s+1;i+1<N;i++){
                if(A[i]==B[s+1]&&A[i+1]==A[s]){
                    ans.push_back(mp(s,i+1));
                    reverse(A.begin()+s,A.begin()+i+1+1);
                    break;
                }
            }
        }
        
        if(ok){
            cout<<"YES\n";
            cout<<si(ans)<<"\n";
            for(auto [l,r]:ans) cout<<l+1<<" "<<r+1<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
}