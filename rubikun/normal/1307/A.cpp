#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,D;cin>>N>>D;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        for(int i=0;i<D;i++){
            for(int j=1;j<N;j++){
                if(A[j]){
                    A[j]--;
                    A[j-1]++;
                    break;
                }
            }
        }
        
        cout<<A[0]<<endl;
    }
}