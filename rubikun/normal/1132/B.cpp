#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> A(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    sort(all(A));
    reverse(all(A));
    
    int M;cin>>M;
    for(int i=0;i<M;i++){
        int a;cin>>a;
        a--;
        cout<<sum-A[a]<<endl;
    }
    
}