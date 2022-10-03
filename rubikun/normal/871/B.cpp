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
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++){
        cout<<"? "<<i<<" "<<0<<endl;
        cin>>A[i];
    }
    
    for(int i=1;i<N;i++){
        cout<<"? "<<0<<" "<<i<<endl;
        cin>>B[i];
    }
    
    int X;
    cout<<"? "<<N-1<<" "<<N-1<<endl;
    cin>>X;
    
    vector<int> ans(N);
    int cnt=0;
    
    for(int a=0;a<N;a++){
        vector<int> C(N),D(N),E(N),pos(N);
        D[0]=a;
        bool ok=true;
        for(int i=1;i<N;i++){
            D[i]=D[0]^B[i]^A[0];
            if(D[i]>=N) ok=false;
        }
        for(int i=0;i<N;i++){
            C[i]=D[0]^A[i];
            if(C[i]>=N) ok=false;
        }
        
        if((C[N-1]^D[N-1])!=X) ok=false;
        
        if(!ok) continue;
        
        for(int i=0;i<N;i++){
            pos[C[i]]=i;
        }
        
        for(int i=0;i<N;i++){
            E[i]=pos[i];
        }
        
        if(D==E){
            ans=C;
            cnt++;
        }
    }
    
    int ma=0;
    for(int i=0;i<20;i++){
        if(N&(1<<i)){
            ma=1<<i;
            break;
        }
    }
    
    cout<<"!"<<endl;
    cout<<min(cnt,ma)<<endl;
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}