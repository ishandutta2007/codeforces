#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int N;cin>>N;
        vector<int> A(N),B(N),diff;
        for(int i=0;i<N;i++){
            //cin>>A[i];
            scanf("%d",&A[i]);
        }
        for(int i=0;i<N;i++){
            //cin>>B[i];
            scanf("%d",&B[i]);
        }
        
        int a=1;
        bool ok=true;
        
        for(int i=0;i<N;i++){
            if(A[i]-B[i]!=0){
                if(a==1){
                    a=A[i]-B[i];
                }
                
                if(a>0||a!=A[i]-B[i]) ok=false;
                
                diff.push_back(i);
            }
        }
        
        for(int k=1;k<diff.size();k++) if(diff[k]-diff[k-1]!=1) ok=false;
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        T--;
        
    }
}