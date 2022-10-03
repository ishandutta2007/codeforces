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

#define ld long double

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> x,y;
        for(int i=0;i<2*N;i++){
            int a,b;cin>>a>>b;
            if(a==0) y.push_back(abs(b));
            else x.push_back(abs(a));
        }
        
        sort(all(x));
        sort(all(y));
        
        ld ans=0;
        
        for(int i=0;i<N;i++){
            ans+=sqrt((ld)x[i]*(ld)(x[i])+(ld)y[i]*(ld)y[i]);
        }
        
        cout<<setprecision(25)<<ans<<endl;
    }
}