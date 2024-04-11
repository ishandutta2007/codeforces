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

vector<int> G[MAX],G2[MAX];
int dis[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        dis[i]=INF;
    }
    
    queue<int> Q;
    dis[0]=0;
    Q.push(0);
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(chmin(dis[to],dis[u]+1)){
                Q.push(to);
                G2[u].push_back(to);
            }
        }
    }
    vector<int> A(N),when(N);
    for(int i=0;i<N;i++){
        cin>>A[i];A[i]--;
        when[A[i]]=i;
    }
    
    for(int i=0;i<N;i++){
        sort(all(G2[i]),[&](auto a,auto b){
            return when[a]<when[b];
        });
    }
    
    vector<int> B;
    
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        B.push_back(u);
        
        for(int to:G2[u]){
            Q.push(to);
        }
    }
    
    if(A==B){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}