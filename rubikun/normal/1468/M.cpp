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

bool aru[MAX];
int id[MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        int M=0,big=0,small=0;
        pair<int,int> ans=mp(-1,-1);
        
        vector<vector<int>> A(N,vector<int>());
        vector<int> zaatu;
        
        for(int i=0;i<N;i++){
            int K;cin>>K;
            A[i].resize(K);
            for(int j=0;j<K;j++){
                int a;cin>>a;
                A[i][j]=a;
                zaatu.push_back(a);
            }
        }
        
        sort(all(zaatu));
        zaatu.erase(unique(all(zaatu)),zaatu.end());
        
        M=si(zaatu);
        
        int D=pow(max(N,M),0.5);
        
        vector<int> sz(M+1),sz2;
        
        vector<int> X,Y;//bigX,smallY
        
        for(int i=0;i<N;i++){
            for(int j=0;j<si(A[i]);j++){
                A[i][j]=lower_bound(all(zaatu),A[i][j])-zaatu.begin();
            }
            if(si(A[i])>=D){
                X.push_back(i);
            }else{
                Y.push_back(i);
            }
            sort(all(A[i]));
        }
        
        big=si(X);
        small=si(Y);
        
        for(int i=0;i<big;i++){
            for(int x:A[X[i]]){
                aru[x]=1;
            }
            
            for(int a=0;a<N;a++){
                int b=X[i];
                if(a==b) continue;
                int cnt=0;
                for(int c:A[a]){
                    if(aru[c]) cnt++;
                }
                if(cnt>=2){
                    ans=mp(a,b);
                }
            }
            
            for(int x:A[X[i]]){
                aru[x]=0;
            }
        }
        
        for(int a:Y){
            for(int i=0;i<si(A[a]);i++){
                for(int j=i+1;j<si(A[a]);j++){
                    sz[A[a][i]+1]++;
                }
            }
        }
        
        for(int i=1;i<=M;i++){
            sz[i]+=sz[i-1];
        }
        
        sz2=sz;
        
        vector<pair<int,int>> B(sz[M]);
        
        for(int a:Y){
            for(int i=0;i<si(A[a]);i++){
                for(int j=i+1;j<si(A[a]);j++){
                    B[sz[A[a][i]]]=mp(A[a][j],a+1);
                    sz[A[a][i]]++;
                }
            }
        }
        
        for(int t=0;t<M;t++){
            for(int i=sz2[t];i<sz2[t+1];i++){
                if(id[B[i].fi]){
                    ans=mp(id[B[i].fi]-1,B[i].se-1);
                }
                id[B[i].fi]=B[i].se;
            }
            for(int i=sz2[t];i<sz2[t+1];i++){
                id[B[i].fi]=0;
            }
        }
        
        if(ans.fi==-1){
            cout<<"-1\n";
        }else{
            cout<<ans.fi+1<<" "<<ans.se+1<<"\n";
        }
        
    }
}