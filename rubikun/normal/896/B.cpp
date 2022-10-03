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
const int mod=1000000007,MAX=105,INF=1<<30;

int main(){
    
    int N,M,C;cin>>N>>M>>C;
    vector<int> now(N);
    
    for(int q=0;q<M;q++){
        int x;cin>>x;
        if(x<=C/2){
            for(int i=0;i<N;i++){
                if(now[i]==0||(now[i]<=C/2&&x<now[i])){
                    now[i]=x;
                    cout<<i+1<<endl;
                    break;
                }
            }
        }else{
            for(int i=N-1;i>=0;i--){
                if(now[i]==0||(now[i]>C/2&&x>now[i])){
                    now[i]=x;
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
        
        bool ok=true;
        for(int i=0;i<N;i++) if(now[i]==0) ok=false;
        for(int i=1;i<N;i++) if(now[i-1]>now[i]) ok=false;
        
        if(ok) return 0;
    }
}