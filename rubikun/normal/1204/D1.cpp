#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=int(S.size());
    vector<int> A(N),B(N);
    int a1=0,b1=0,amax=0,bmax=0;
    for(int i=0;i<N;i++){
        if(S[i]=='1') A[i]=1;
        else A[i]=0;
    }
    
    for(int i=N-1;i>=0;i--){
        if(A[i]==0){
            amax++;
            bmax++;
            B[i]=0;
        }else{
            a1++;
            amax=max(amax,a1);
            if(bmax+1<=amax){
                B[i]=0;
                bmax++;
            }else{
                B[i]=1;
                b1++;
                bmax=max(bmax,b1);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<B[i];
    }
    cout<<endl;
    
}