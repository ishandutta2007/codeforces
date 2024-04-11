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

int to[33][MAX];

vector<int> fr[MAX];

vector<int> can[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> P(N),A(N),deta(N);
    for(int i=0;i<N;i++){
        cin>>P[i];P[i]--;
        deta[P[i]]=true;
    }
    int mada=0;
    for(int i=0;i<N;i++) if(!deta[i]) mada++;
    int ma=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        chmax(ma,A[i]);
    }
    int turn=(ma-N)/mada;
    
    if(turn==0){
        for(int i=0;i<N;i++) cout<<A[i]<<" ";
        cout<<endl;
        return 0;
    }
    
    for(int i=0;i<N;i++) to[0][i]=P[i];
    for(int t=1;t<32;t++){
        for(int i=0;i<N;i++){
            to[t][i]=to[t-1][to[t-1][i]];
        }
    }
    
    for(int i=0;i<N;i++){
        int now=i;
        for(int t=30;t>=0;t--){
            if(turn&(1<<t)) now=to[t][now];
        }
        fr[now].push_back(i);
    }
    
    vector<int> ans(N,-1),used(N+1);
    vector<int> lim(N,-1);
    
    for(int i=0;i<N;i++){
        if(si(fr[i])){
            ans[fr[i][0]]=A[i];
            used[A[i]]=true;
            for(int j=1;j<si(fr[i]);j++){
                lim[fr[i][j]]=A[i]+1;
                can[A[i]+1].push_back(fr[i][j]);
                //cout<<fr[i][j]<<" "<<A[i]+1<<endl;
            }
        }
    }
    
    priority_queue<int,vector<int>,greater<int>> PQ;
    for(int i=1;i<=N;i++){
        for(int pos:can[i]) PQ.push(pos);
        if(used[i]) continue;
        ans[PQ.top()]=i;
        PQ.pop();
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}