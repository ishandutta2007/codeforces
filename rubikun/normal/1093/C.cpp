#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> A(N),B(N/2);
    for(int i=0;i<N/2;i++){
        cin>>B[i];
    }
    for(int i=0;i<N/2;i++){
        A[i]=0;
        A[N-1-i]=B[i];
        if(i){
            if(A[i-1]>A[i]){
                A[i]=A[i-1];
                A[N-1-i]=B[i]-A[i];
            }
            if(A[N-1-i]>A[N-i]){
                A[N-1-i]=A[N-i];
                A[i]=B[i]-A[N-1-i];
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
}