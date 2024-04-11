#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=210003;
const ll INF=1LL<<60;
int N;
vector<int> ansa,ansb;

vector<int> dx={1,1,1,-1,-1,-1},d1={1,0,-1,1,0,-1};

void DFS(vector<int> A,vector<int> B,int k){
    if(ansa.size()==N+1) return;
    
    if(k==N){
        bool ok=true;
        for(int i=0;i<=N;i++) if(abs(A[i])>1||abs(B[i])>1) ok=false;
        if(A[N]*B[N-1]==-1) ok=false;
        
        if(ok){
            if(A[N]==-1){
                for(int i=0;i<=N;i++){
                    A[i]*=-1;
                    B[i]*=-1;
                }
            }
            ansa=A;
            ansb=B;
        }
        
        return;
    }
    
    bool ok=true;
    for(int i=0;i<=k;i++) if(abs(A[i])>1||abs(B[i])>1) ok=false;
    
    if(!ok) return;
    
    for(int j=0;j<6;j++){
        vector<int> ne=B;
        
        for(int i=0;i<=k;i++){
            ne[i+1]+=A[i]*dx[j];
            ne[i]+=A[i]*d1[j];
        }
        
        DFS(ne,A,k+1);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    vector<int> A(N+1),B(N+1);
    A[0]=1;
    B[0]=0;
    
    DFS(A,B,0);
    
    if(ansa.size()==N+1){
        cout<<N<<"\n";
        for(int i=0;i<N+1;i++) cout<<ansa[i]<<" ";
        cout<<"\n";
        
        cout<<N-1<<"\n";
        for(int i=0;i<N;i++) cout<<ansb[i]<<" ";
        cout<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}