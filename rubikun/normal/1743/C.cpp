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
        string S;cin>>S;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        int ans=0;
        int i=N-1;
        while(i>=0){
            if(S[i]=='0'){
                i--;
            }else{
                int j=i;
                while(j>=0&&S[j]=='1') j--;
                vector<int> B;
                for(int k=max(0,j);k<=i;k++) B.push_back(A[k]);
                sort(all(B));
                if(j==-1){
                    for(int t=0;t<si(B);t++) ans+=B[t];
                }else{
                    for(int t=1;t<si(B);t++) ans+=B[t];
                }
                //for(int t=1;t<si(B);t++) ans+=B[t];
                i=j-1;
            }
        }
        
        cout<<ans<<"\n";
    }
}