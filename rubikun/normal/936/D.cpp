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
const int mod=1000000007,MAX=6100005,INF=1<<30;

//Union Find

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int dp[MAX][2];
bool par[MAX][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M1,M2,T;cin>>N>>M1>>M2>>T;
    vector<int> use={0,N+1};
    vector<int> A(M1),B(M2);
    for(int i=0;i<M1;i++){
        int t;cin>>t;
        use.push_back(t-1);
        use.push_back(t);
        use.push_back(t+1);
        A[i]=t;
    }
    for(int i=0;i<M2;i++){
        int t;cin>>t;
        use.push_back(t-1);
        use.push_back(t);
        use.push_back(t+1);
        B[i]=t;
    }
    sort(all(use));
    use.erase(unique(all(use)),use.end());
    
    for(int i=0;i<MAX;i++) for(int j=0;j<2;j++) dp[i][j]=-INF;
    dp[0][0]=dp[0][1]=0;
    
    for(int i=1;i<si(use);i++){
        if(dp[i-1][0]>=0){
            if(binary_search(all(A),use[i])){
                if(dp[i-1][0]>=T) chmax(dp[i][0],dp[i-1][0]+use[i]-use[i-1]-T);
            }else{
                chmax(dp[i][0],dp[i-1][0]+use[i]-use[i-1]);
            }
        }
        if(dp[i-1][1]>=0){
            if(binary_search(all(B),use[i])){
                if(dp[i-1][1]>=T) chmax(dp[i][1],dp[i-1][1]+use[i]-use[i-1]-T);
            }else{
                chmax(dp[i][1],dp[i-1][1]+use[i]-use[i-1]);
            }
        }
        
        int a=dp[i][0],b=dp[i][1];
        if(!binary_search(all(A),use[i])){
            if(chmax(dp[i][0],min(T,b))){
                par[i][0]=true;
            }
        }
        if(!binary_search(all(B),use[i])){
            if(chmax(dp[i][1],min(T,a))){
                par[i][1]=true;
            }
        }
    }
    
    for(int i=0;i<si(use);i++){
        //cout<<use[i]<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    
    if(dp[si(use)-1][0]<0&&dp[si(use)-1][1]<0){
        cout<<"No"<<endl;
        return 0;
    }
    
    cout<<"Yes"<<endl;
    
    int now=si(use)-1,f;
    if(dp[si(use)-1][0]>=0) f=0;
    if(dp[si(use)-1][1]>=0) f=1;
    
    vector<int> turn;
    vector<pair<int,int>> shoot;
    
    int last=N+T+3;
    
    while(now>=0){
        if(now==0){
            if(f==1){
                turn.push_back(0);
                f=0;
            }
            break;
        }
        
        if(par[now][f]){
            turn.push_back(min(last,use[now]));
            f^=1;
        }
        
        int len=dp[now][f]-dp[now-1][f];
        if(len==use[now]-use[now-1]){
            now--;
        }else{
            shoot.push_back(mp(min(last-T,use[now]-1),f+1));
            last=shoot.back().fi;
            now--;
        }
    }
    
    reverse(all(shoot));
    reverse(all(turn));
    
    cout<<si(turn)<<endl;
    for(int a:turn) cout<<a<<" ";
    cout<<endl;
    
    cout<<si(shoot)<<endl;
    for(auto a:shoot) cout<<a.fi<<" "<<a.se<<"\n";
    
    return 0;
}