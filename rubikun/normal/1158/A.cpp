#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<50;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<int> A(N),B(M);
    for(int i=0;i<N;i++){
        //cin>>A[i];
        scanf("%d",&A[i]);
    }
    for(int i=0;i<M;i++){
        //cin>>B[i];
        scanf("%d",&B[i]);
    }
    
    sort(all(A));
    sort(all(B));
    
    if(A[N-1]>B[0]){
        cout<<-1<<endl;
        return 0;
    }
    
    if(N==1&&A[N-1]!=B[0]){
        cout<<-1<<endl;
        return 0;
    }
    
    if(A[N-1]==B[0]){
        ll sum=0;
        for(int i=0;i<N-1;i++) sum+=A[i];
        sum*=M;
        for(int i=0;i<M;i++) sum+=B[i];
        
        cout<<sum<<endl;
    }else{
        ll sum=0;
        for(int i=0;i<N-1;i++) sum+=A[i];
        sum*=M;
        sum-=A[N-2];
        sum+=B[0];
        sum+=A[N-1];
        for(int i=1;i<M;i++) sum+=B[i];
        
        cout<<sum<<endl;
    }
}