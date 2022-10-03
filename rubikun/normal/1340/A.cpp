#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),when(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]--;
            when[A[i]]=i;
        }
        
        int mini=A[0];
        
        bool ok=true;
        
        for(int i=1;i<N;i++){
            if(A[i-1]+1==A[i]) continue;
            else{
                if(A[i]>mini) ok=false;
                else chmin(mini,A[i]);
            }
        }
        
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}