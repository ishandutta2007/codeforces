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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> P(N),Q(N),deta(N);
        for(int i=0;i<N;i++){
            cin>>P[i];P[i]--;
        }
        if(N==1){
            cout<<-1<<"\n";
            continue;
        }
        
        for(int i=0;i<N-2;i++){
            for(int j=0;j<N;j++){
                if(!deta[j]&&P[i]!=j){
                    Q[i]=j;
                    deta[j]=true;
                    break;
                }
            }
        }
        
        vector<int> X;
        for(int i=0;i<N;i++) if(!deta[i]) X.push_back(i);
        
        if(X[0]!=P[N-2]&&X[1]!=P[N-1]){
            Q[N-2]=X[0];
            Q[N-1]=X[1];
        }else{
            Q[N-2]=X[1];
            Q[N-1]=X[0];
        }
        
        for(int i=0;i<N;i++) cout<<Q[i]+1<<" ";
        cout<<"\n";
    }
}