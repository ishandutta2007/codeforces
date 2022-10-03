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
    
    int N;cin>>N;
    vector<int> A(2*N);
    for(int i=0;i<2*N;i++) cin>>A[i];
    
    int ans=0;
    
    for(int i=0;i<2*N;i+=2){
        for(int j=i+1;j<2*N;j++){
            if(A[i]==A[j]){
                for(int k=j;k-1>=i+1;k--){
                    ans++;
                    swap(A[k-1],A[k]);
                }
                break;
            }
        }
    }
    
    cout<<ans<<endl;
}