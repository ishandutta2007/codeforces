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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,A,B;cin>>N>>A>>B;
        if(abs(A-B)>1||A+B>N-2){
            cout<<-1<<"\n";
        }else{
            vector<int> ans(N);
            if(A==B+1){
                for(int i=0;i<2*A;i++){
                    if(i&1) ans[i]=N-i/2;
                    else ans[i]=(i/2)+1;
                }
                for(int i=2*A;i<N;i++){
                    ans[i]=N-A+(2*A-i);
                }
            }else if(A==B){
                for(int i=0;i<2*A;i++){
                    if(i&1) ans[i]=N-i/2;
                    else ans[i]=(i/2)+1;
                }
                for(int i=2*A;i<N;i++){
                    ans[i]=A+1+(i-2*A);
                }
            }else{
                for(int i=0;i<2*B;i++){
                    if(i&1) ans[i]=i/2+1;
                    else ans[i]=N-i/2;
                }
                for(int i=2*B;i<N;i++){
                    ans[i]=B+1+(i-2*B);
                }
            }
            
            for(int i=0;i<N;i++) cout<<ans[i]<<" ";
            cout<<"\n";
        }
    }
}