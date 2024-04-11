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
const int mod=1000000007,MAX=4005;
const ll INF=1LL<<60;
ll dis[MAX];

void dijkstra(vector<int> &A){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    
    for(int diff:A){
        dis[2000+diff]=1;
        PQ.push(mp(1,2000+diff));
    }
    
    while(!PQ.empty()){
        ll a=PQ.top().first;
        int b=PQ.top().second;
        PQ.pop();
        if(dis[b]<a) continue;
        
        for(int diff:A){
            int to=b+diff;
            if(to<0||to>=4000) continue;
            if(dis[to]>dis[b]+1){
                dis[to]=dis[b]+1;
                PQ.push(mp(dis[to],to));
            }
        }
    }
    return;
}//a,d

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>K>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    A.erase(unique(all(A)),A.end());
    
    N=si(A);
    
    if(A[0]>K||A[N-1]<K){
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=0;i<=4000;i++) dis[i]=INF;
    
    for(int i=0;i<N;i++) A[i]=A[i]-K;
    
    dijkstra(A);
    
    if(dis[2000]>=INF) dis[2000]=-1;
    cout<<dis[2000]<<endl;
}