#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N),B(N),turn(N+1),mini(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        turn[A[i]]=i+1;
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
        B[i]=turn[B[i]];
    }
    mini[N-1]=B[N-1];
    for(int i=N-2;i>=0;i--){
        mini[i]=min(mini[i+1],B[i]);
    }
    
    int ans=0;
    
    for(int i=0;i<N-1;i++){
        if(B[i]>mini[i+1]) ans++;
    }
    
    cout<<ans<<endl;
    
}