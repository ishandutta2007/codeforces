#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    bool ok=true;
    for(int i=1;i<N;i++) if(A[i-1]>A[i]) ok=false;
    
    if(ok){
        cout<<0<<endl;
        return 0;
    }
    
    int left=0,right=M;
    
    while(right-left>1){
        int mid=(left+right)/2;
        
        bool ok=true;
        int now;
        if(A[0]+mid>=M) now=0;
        else now=A[0];
        
        for(int i=1;i<N;i++){
            if(now==A[i]) continue;
            if(now>A[i]){
                if(A[i]+mid>=now) continue;
                else ok=false;
            }else{
                if(A[i]+mid<M) now=A[i];
                else{
                    if((A[i]+mid)%M>=now) continue;
                    else now=A[i];
                }
            }
        }
        
        if(ok) right=mid;
        else left=mid;
    }
    
    cout<<right<<endl;
}