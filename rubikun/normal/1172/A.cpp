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
    vector<int> A(N),B(N),pos(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]--;
        if(A[i]>=0) pos[A[i]]=N;
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
        B[i]--;
        if(B[i]>=0) pos[B[i]]=i;
    }
    if(pos[0]!=N){
        bool ok=true;
        int ti=pos[0];
        for(int i=1;i<N;i++){
            if(pos[i]==N){
                int need=N-i;
                if(need>ti) ok=false;
            }else{
                if(i<=pos[i]){
                    if(pos[i]-i!=ti) ok=false;
                }else{
                    int need=pos[i]+1+N-i;
                    if(need>ti) ok=false;
                }
            }
        }
        
        if(ok){
            cout<<ti<<endl;
            return 0;
        }
    }
    
    int ma=0;
    
    for(int i=0;i<N;i++){
        if(pos[i]!=N){
            if(pos[i]<i) ma=ma;
            else ma=max(ma,pos[i]-(i-1));
        }
    }
    
    cout<<N+ma<<endl;
}