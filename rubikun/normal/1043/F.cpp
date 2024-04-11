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
const int mod1=1000000007,MAX=300005,INF=1<<30;

bool aru[MAX];

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int> G[MAX];

int dis[MAX];

void BFS(vector<int> &s){
    queue<int> Q;
    for(int a:s) Q.push(a);
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:s){
            int g=gcd(to,u);
            if(chmin(dis[g],dis[u]+1)){
                Q.push(g);
            }
            if(g==1){
                cout<<dis[1]<<endl;
                return;
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    for(int i=0;i<N;i++){
        int a;cin>>a;
        aru[a]=1;
    }
    
    vector<int> use;
    
    for(int i=1;i<=300000;i++) dis[i]=INF;
    
    for(int i=1;i<=300000;i++){
        if(!aru[i]) continue;
        for(int j=2;i*j<=300000;j++){
            aru[i*j]=0;
        }
        use.push_back(i);
        dis[i]=1;
    }
    
    int g=0;
    for(int a:use) g=gcd(g,a);
    
    if(g!=1){
        cout<<-1<<endl;
        return 0;
    }
    
    BFS(use);
    
}