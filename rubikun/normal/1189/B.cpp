#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());*/
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    if(A[N-3]+A[N-2]<=A[N-1]) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<A[N-3]<<" "<<A[N-1]<<" "<<A[N-2];
        for(int i=0;i<N-3;i++){
            cout<<" "<<A[i];
        }
        cout<<endl;
    }
}