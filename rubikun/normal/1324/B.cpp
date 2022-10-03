#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<20;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),fi(N,INF),la(N,-INF);
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]--;
            fi[A[i]]=min(fi[A[i]],i);
            la[A[i]]=max(la[A[i]],i);
        }
        bool ok=false;
        
        for(int i=0;i<N;i++){
            if(la[i]-fi[i]>=2) ok=true;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}