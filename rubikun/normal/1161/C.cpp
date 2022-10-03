#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    
    int cnt=0;
    for(int i=0;i<N;i++) if(A[i]==A[0]) cnt++;
    
    if(cnt<=N/2) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}