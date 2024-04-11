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
const int mod=1000000007,MAX=205;
const ll INF=1LL<<60;

ll dp[65][MAX][MAX];
ll ans[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll X;cin>>X;
    vector<ll> AA(N);
    for(int i=0;i<N;i++) cin>>AA[i];
    vector<string> S(N);
    set<string> SE;
    for(int i=0;i<N;i++){
        cin>>S[i];
        for(int j=0;j<=si(S[i]);j++){
            SE.insert(S[i].substr(0,j));
        }
    }
    vector<string> T;
    for(auto a:SE) T.push_back(a);
    
    int M=si(T);
    
    for(int t=0;t<65;t++) for(int i=0;i<M;i++) for(int j=0;j<M;j++) dp[t][i][j]=-INF;
    
    for(int i=0;i<M;i++){
        string A=T[i];
        for(char c='a';c<='z';c++){
            A+=c;
            int score=0;
            for(int j=0;j<N;j++){
                if(si(A)>=si(S[j])&&A.substr(si(A)-si(S[j]))==S[j]) score+=AA[j];
            }
            pair<int,int> ma=mp(-1,-1);
            for(int j=0;j<M;j++){
                if(si(A)>=si(T[j])&&A.substr(si(A)-si(T[j]))==T[j]) chmax(ma,mp(si(T[j]),j));
            }
            A.pop_back();
            if(ma.fi!=-1){
                dp[0][i][ma.se]=score;
                //cout<<i<<" "<<ma.se<<" "<<score<<endl;
            }
        }
    }
    
    for(int t=1;t<65;t++){
        for(int i=0;i<M;i++){
            for(int k=0;k<M;k++){
                for(int j=0;j<M;j++){
                    chmax(dp[t][i][j],dp[t-1][i][k]+dp[t-1][k][j]);
                }
            }
        }
    }
    
    for(int i=1;i<M;i++) ans[i]=-INF;
    
    for(int t=60;t>=0;t--){
        if(X&(1LL<<t)){
            vector<ll> nex(M,-INF);
            for(int i=0;i<M;i++){
                for(int j=0;j<M;j++){
                    chmax(nex[j],ans[i]+dp[t][i][j]);
                }
            }
            for(int i=0;i<M;i++) ans[i]=nex[i];
        }
    }
    
    ll ma=-INF;
    
    for(int i=0;i<M;i++) chmax(ma,ans[i]);
    
    cout<<ma<<endl;
}