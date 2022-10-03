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
    
    int N;cin>>N;
    vector<ll> imo(N+1),A(N+1);
    
    for(int i=1;i<=N;i++) cin>>A[i];
    
    for(int i=2;i<=N;i++){
        int u=i-2;
        int ne=1;
        for(int k=1;k*k<=u;k++){
            int v=1+u/k;
            if(A[v]>A[i]){
                imo[k]++;
                imo[k+1]--;
            }
            ne=k+1;
        }
        
        while(ne<=N-1){
            
            int v=1+u/ne;
            
            if(v==1){
                if(A[v]>A[i]){
                    imo[ne]++;
                    imo[N]--;
                }
                break;
            }else{
                int to=u/(u/ne)+1;
                if(A[v]>A[i]){
                    imo[ne]++;
                    imo[to]--;
                }
                ne=to;
            }
        }
    }
    
    for(int k=1;k<=N;k++) imo[k]+=imo[k-1];
    
    for(int i=1;i<N;i++) cout<<imo[i]<<" ";
    cout<<endl;
}