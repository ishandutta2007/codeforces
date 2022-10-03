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

vector<int> when[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,x,y;cin>>N>>x>>y;
        y-=x;
        for(int i=0;i<=N+1;i++) when[i].clear();
        vector<int> A(N,0),B(N),cnt(N+3);
        for(int i=0;i<N;i++){
            cin>>B[i];
            cnt[B[i]]++;
            when[B[i]].push_back(i);
        }
        int free=-1;
        for(int i=1;i<=N+1;i++){
            if(cnt[i]==0) free=i;
        }
        priority_queue<pair<int,int>> PQ;
        for(int i=1;i<=N+1;i++){
            PQ.push(mp(si(when[i]),i));
        }
        
        while(x--){
            auto a=PQ.top();PQ.pop();
            A[when[a.se].back()]=a.se;
            when[a.se].pop_back();
            PQ.push(mp(a.fi-1,a.se));
        }
        
        pair<int,int> ma=mp(0,0);
        for(int i=1;i<=N+1;i++){
            chmax(ma,mp(si(when[i]),i));
        }
        
        int sum=0;
        for(int i=1;i<=N+1;i++){
            if(i!=ma.se) sum+=si(when[i]);
        }
        
        if(sum+min(ma.fi,sum)<y){
            cout<<"NO\n";
            continue;
        }
        
        vector<pair<int,int>> cycle;
        for(int i=1;i<=N+1;i++){
            if(i==ma.se){
                for(int j=0;j<min(ma.fi,sum);j++) cycle.push_back(mp(when[i][j],i));
            }else{
                for(int j=0;j<si(when[i]);j++) cycle.push_back(mp(when[i][j],i));
            }
        }
        
        for(int t=0;t<y;t++){
            A[cycle[t].fi]=cycle[(t+si(cycle)/2)%si(cycle)].se;
        }
        
        for(int i=0;i<N;i++) if(A[i]==0) A[i]=free;
        
        cout<<"YES\n";
        for(int a:A) cout<<a<<" ";
        cout<<"\n";
        
    }
}