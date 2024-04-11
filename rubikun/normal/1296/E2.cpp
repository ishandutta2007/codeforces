#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
int dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        A[i]=S[i]-'a'+1;
    }
    
    for(int i=1;i<MAX;i++) dp[i]=INF;
    
    for(int i=N-1;i>=0;i--){
        auto it=lower_bound(dp,dp+MAX-1,A[i]);
        *it=A[i];
    }
    
    int ans=0;
    for(int i=0;i<MAX;i++){
        if(dp[i]==INF){
            ans=i-1;
            break;
        }
    }
    
    vector<int> res(N);
    
    vector<vector<int>> use(27,vector<int>(27));
    
    for(int i=N-1;i>=0;i--){
        int ma=-1;
        for(int k=1;k<=26;k++){
            bool ok=true;
            for(int j=1;j<A[i];j++){
                if(use[j][k]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                ma=k;
                break;
            }
        }
        res[i]=ma;
        use[A[i]][ma]=1;
    }
    cout<<ans<<endl;
    for(int i=0;i<N;i++) cout<<res[i]<<" ";
    cout<<endl;
}