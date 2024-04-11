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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<60;

const int N=120;

ll state[N][N];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll t,x,y;cin>>t>>x>>y;
        if(t<x+y){
            cout<<"NO\n";
            continue;
        }
        ll st=t-(x+y);
        
        memset(state,0,sizeof(state));
        
        state[0][0]=st;
        for(int q=0;q<=2*N-2;q++){
            
            for(int h=0;h<N;h++){
                int w=q-h;
                if(w<0||w>=N) continue;
                if(w+1<N) state[h][w+1]+=(state[h][w]+1)/2;
                if(h+1<N) state[h+1][w]+=(state[h][w])/2;
            }
        }
        
        int nowh=0,noww=0;
        for(int q=0;q<x+y;q++){
            if(state[nowh][noww]&1){
                nowh++;
            }else{
                noww++;
            }
            if(noww>=N||nowh>=N) break;
        }
        
        if(nowh==x&&noww==y) cout<<"YES\n";
        else cout<<"NO\n";
    }
}