#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    int center=0;
    bool flag=true;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==N) center=i;
    }
    for(int i=1;i<=center;i++){
        if(A[i-1]>A[i]) flag=false;
    }
    for(int i=N-2;i>=center;i--){
        if(A[i+1]>A[i]) flag=false;
    }
    
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}