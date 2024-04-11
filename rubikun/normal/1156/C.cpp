#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,Z;cin>>N>>Z;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    int ans=0;
    priority_queue<int,vector<int>,greater<int>> PQ;
    
    for(int i=0;i<(N+1)/2;i++){
        PQ.push(A[i]);
    }
    
    for(int i=(N+1)/2;i<N;i++){
        int a=PQ.top();
        if(A[i]-a>=Z){
            ans++;
            PQ.pop();
        }
    }
    
    cout<<ans<<endl;
}