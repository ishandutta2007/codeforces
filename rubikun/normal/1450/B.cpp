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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        vector<int> x(N),y(N);
        for(int i=0;i<N;i++) cin>>x[i]>>y[i];
        bool ok=false;
        
        for(int k=0;k<N;k++){
            bool check=true;
            for(int i=0;i<N;i++){
                if(abs(x[i]-x[k])+abs(y[i]-y[k])>K) check=false;
            }
            if(check) ok=true;
        }
        
        if(ok) cout<<1<<endl;
        else cout<<-1<<endl;
    }
}