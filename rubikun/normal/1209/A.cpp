#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    
    for(int i=0;i<N;i++){
        if(A[i]==-1) continue;
        for(int j=i+1;j<N;j++){
            if(A[j]==-1) continue;
            if(A[j]%A[i]==0){
                A[j]=-1;
            }
        }
        A[i]=-1;
        ans++;
    }
    
    cout<<ans<<endl;
    
}