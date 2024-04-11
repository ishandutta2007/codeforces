#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    
    while(Q){
        int N;cin>>N;
        vector<int> A(N),B(N);
        int asum=0,bsum=0;
        bool ok=false;
        
        for(int i=0;i<N;i++){
            string S;cin>>S;
            for(int j=0;j<S.size();j++){
                if(S[j]=='1') B[i]++;
            }
            A[i]=S.size();
            
            asum+=A[i];
            bsum+=B[i];
            
            if(A[i]%2==1) ok=true;
        }
        
        if(bsum%2==0) cout<<N<<endl;
        else if(!ok) cout<<N-1<<endl;
        else cout<<N<<endl;
        
        Q--;
    }
}