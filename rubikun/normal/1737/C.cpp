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
        map<int,int> H,W;
        for(int i=0;i<3;i++){
            int a,b;cin>>a>>b;
            H[a]++;
            W[b]++;
        }
        int h,w;
        for(auto a:H){
            if(a.se==2) h=a.fi;
        }
        for(auto a:W){
            if(a.se==2) w=a.fi;
        }
        
        int x,y;cin>>x>>y;
        
        if(h==N){
            h=N+1-h;
            x=N+1-x;
        }
        if(w==N){
            w=N+1-w;
            y=N+1-y;
        }
        
        if(h==1&&w==1){
            if(x==1||y==1) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            if(abs(h-x)%2==0||abs(w-y)%2==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}