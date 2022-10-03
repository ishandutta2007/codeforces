#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1<<19,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N;cin>>N;
        int cnt=0;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        priority_queue<int> PQ;
        for(int i=N-1;i>=0;i--){
            PQ.push(-A[i]);
            int a=-PQ.top();
            if(A[i]>a) cnt++;
        }
        cout<<cnt<<endl;
    }
}