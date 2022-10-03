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
const int mod=1000000007,MAX=300005,INF=1<<30;

ll rui[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    int NN=N-1,t=0;
    while(NN){
        NN/=K;
        t++;
    }
    cout<<t<<"\n";
    rui[0]=1;
    for(int i=1;;i++){
        if(rui[i-1]>1e9) break;
        rui[i]=rui[i-1]*K;
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=t;k>=0;k--){
                ll a=i/rui[k],b=j/rui[k];
                if(a!=b){
                    cout<<k+1<<" ";
                    break;
                }
            }
        }
    }
    
    cout<<"\n";
    
}