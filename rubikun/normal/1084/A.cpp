#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int ans=INF;
    
    for(int k=0;k<N;k++){
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=(abs(k-i)+abs(i)+abs(k)+abs(k)+abs(i)+abs(k-i))*A[i];
        }
        ans=min(ans,sum);
    }
    
    cout<<ans<<endl;
}