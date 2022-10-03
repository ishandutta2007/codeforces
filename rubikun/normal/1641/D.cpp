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
const int mod=998244353,MAX=100005,INF=1<<30;

bitset<MAX> bi;
bitset<MAX> ng[305];
const int D=10000;

vector<int> wh[500005];
int big[500005];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<vector<int>> A(N,vector<int>(M));
    vector<int> use;use.reserve(N*M);
    vector<int> W(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
            use.push_back(A[i][j]);
        }
        sort(all(A[i]));
        cin>>W[i];
    }
    vector<int> id(N);iota(all(id),0);
    sort(all(id),[&](auto a,auto b){
        return W[a]<W[b];
    });
    vector<vector<int>> nA=A;
    for(int i=0;i<N;i++){
        nA[i]=A[id[i]];
    }
    A=nA;
    sort(all(W));
    
    sort(all(use));use.erase(unique(all(use)),use.end());
    int K=si(use);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            A[i][j]=lower_bound(all(use),A[i][j])-use.begin();
            if(j==0||A[i][j-1]!=A[i][j]) wh[A[i][j]].push_back(i);
        }
    }
    memset(big,-1,sizeof(big));
    int t=0;
    for(int i=0;i<K;i++){
        if(si(wh[i])>=D){
            big[i]=t;
            for(int j=0;j<N;j++) ng[t][j]=true;
            for(int a:wh[i]) ng[t][a]=false;
            t++;
        }
    }
    
    for(int i=0;i<N;i++) bi[i]=true;
    
    ll ans=(1LL<<60);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(j&&A[i][j-1]==A[i][j]) continue;
            if(big[A[i][j]]!=-1){
                bi&=ng[big[A[i][j]]];
            }else{
                for(int a:wh[A[i][j]]) bi[a]=false;
            }
        }
        int x=bi._Find_first();
        if(x<N){
            chmin(ans,(ll)W[i]+W[x]);
        }
        for(int j=0;j<M;j++){
            if(j&&A[i][j-1]==A[i][j]) continue;
            if(big[A[i][j]]!=-1){
                bi|=ng[big[A[i][j]]];
            }else{
                for(int a:wh[A[i][j]]) bi[a]=true;
            }
        }
    }
    
    if(ans==(1LL<<60)) ans=-1;
    cout<<ans<<endl;
}