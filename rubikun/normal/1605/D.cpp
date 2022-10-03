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
vector<int> G[MAX];
int color[MAX];

void make(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        color[to]=3-color[u];
        make(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
            color[i]=0;
        }
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        color[0]=1;
        make(0,-1);
        vector<int> A,B;
        for(int i=0;i<N;i++){
            if(color[i]==1) A.push_back(i+1);
            else B.push_back(i+1);
        }
        if(si(A)>si(B)) swap(A,B);
        vector<int> X;X.push_back(1);
        int rem=N-1;
        while(1){
            if(rem==0) break;
            if(X.back()*2<=rem){
                int Y=X.back()*2;
                rem-=Y;
                X.push_back(Y);
            }else{
                break;
            }
        }
        
        vector<int> used(N+1),ans(N+1);
        for(int i=si(X)-1;i>=0;i--){
            if(si(A)>=X[i]){
                for(int j=(1<<i);j<(1<<(i+1));j++){
                    ans[A.back()]=j;
                    used[j]=true;
                    A.pop_back();
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(!used[i]){
                ans[B.back()]=i;
                used[i]=true;
                B.pop_back();
            }
        }
        
        for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}