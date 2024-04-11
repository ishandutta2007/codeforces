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
    vector<int> A(2*N);
    for(int i=0;i<2*N;i++) cin>>A[i];
    sort(all(A));
    
    if(A[0]==A[2*N-1]) cout<<-1<<endl;
    else{
        for(int i=0;i<2*N;i++) cout<<A[i]<<" ";
        cout<<endl;
    }
}