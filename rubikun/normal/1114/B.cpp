#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<pair<ll,int>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i;
    }
    
    sort(all(A));
    reverse(all(A));
    
    ll sum=0;
    
    vector<int> B;
    
    for(int i=0;i<M*K;i++){
        sum+=A[i].first;
        B.push_back(A[i].second);
    }
    sort(all(B));
    
    cout<<sum<<endl;
    
    for(int i=0;i<K-1;i++){
        cout<<B[i*M+M-1]+1<<" ";
    }
    cout<<endl;
    
}