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
const int mod=1000000007,MAX=200005;
const ll INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<int> p(N);
        for(int i=0;i<N;i++){
            cin>>p[i];
            p[i]--;
        }
        int ok=N;
        for(int i=N-1;i>=0;i--){
            if(p[i]==i) ok=i;
            else break;
        }
        
        double ans=1;
        
        for(int i=0;i<M;i++){
            int a;double b;cin>>a>>b;
            if(a>=ok) ans*=(1.0-b);
        }
        
        if(ok==0) ans=0;
        
        cout<<fixed<<setprecision(25)<<(1.0-ans)<<"\n";
    }
}