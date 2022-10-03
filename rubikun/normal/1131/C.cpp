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
    
    int N;cin>>N;
    deque<int> deq;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    deq.push_back(A[0]);
    
    for(int i=1;i<N;i++){
        if(i&1) deq.push_front(A[i]);
        else deq.push_back(A[i]);
    }
    
    for(int i=0;i<N;i++) cout<<deq[i]<<" ";
    cout<<endl;
}