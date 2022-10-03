#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    ll H;cin>>N>>H;
    vector<ll> A(N+1);
    for(int i=0;i<N;i++) cin>>A[i];
    A[N]=INF;
    
    int left=1,right=N+1;
    while(right-left>1){
        int mid=(left+right)/2;
        
        priority_queue<ll> PQ;
        for(int i=0;i<mid;i++){
            PQ.push(A[i]);
        }
        
        ll sum=0;
        
        for(int i=0;i<mid/2;i++){
            ll a=PQ.top();
            PQ.pop();
            PQ.pop();
            sum+=a;
        }
        
        if(!PQ.empty()){
            ll a=PQ.top();
            PQ.pop();
            sum+=a;
        }
        
        if(sum<=H) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}