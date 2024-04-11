#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<pair<int,int>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i+1;
    }
    
    sort(all(A));
    reverse(all(A));
    
    int ans=0;
    
    vector<int> B(N);
    
    for(int i=0;i<N;i++){
        ans+=A[i].first*i+1;
        B[i]=A[i].second;
    }
    
    cout<<ans<<endl;
    for(int i=0;i<N;i++){
        cout<<B[i]<<" ";
    }
    
    cout<<endl;
}