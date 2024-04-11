#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> check;
    for(int i=2;i<=N;i++){
        if(N%i==0) check.push_back(i);
    }
    vector<vector<int>> A(N,vector<int>(N));
    for(int i=0;i<N;i++){
        char S[N/4];
        scanf("%s",S);
        for(int j=0;j<N/4;j++){
            if(0<=S[j]-'0'&&S[j]-'0'<=9){
                int x=S[j]-'0';
                for(int k=0;k<4;k++){
                    if(x&(1<<k)) A[i][j*4+3-k]=1;
                    else A[i][j*4+3-k]=0;
                }
            }else if(S[j]=='A'){
                A[i][j*4]=1;
                A[i][j*4+1]=0;
                A[i][j*4+2]=1;
                A[i][j*4+3]=0;
            }else if(S[j]=='B'){
                A[i][j*4]=1;
                A[i][j*4+1]=0;
                A[i][j*4+2]=1;
                A[i][j*4+3]=1;
            }else if(S[j]=='C'){
                A[i][j*4]=1;
                A[i][j*4+1]=1;
                A[i][j*4+2]=0;
                A[i][j*4+3]=0;
            }else if(S[j]=='D'){
                A[i][j*4]=1;
                A[i][j*4+1]=1;
                A[i][j*4+2]=0;
                A[i][j*4+3]=1;
            }else if(S[j]=='E'){
                A[i][j*4]=1;
                A[i][j*4+1]=1;
                A[i][j*4+2]=1;
                A[i][j*4+3]=0;
            }else if(S[j]=='F'){
                A[i][j*4]=1;
                A[i][j*4+1]=1;
                A[i][j*4+2]=1;
                A[i][j*4+3]=1;
            }
        }
    }
    
    int ans=1;
    
    vector<int> bad;
    
    for(int k=check.size()-1;k>=0;k--){
        int M=check[k];
        bool ok=true;
        int x=rand()%N,y=rand()%N;
        for(int i=x;i<N+x;i++){
            int ii=i;
            if(ii>=N) ii-=N;
            for(int j=y;j<N+y;j++){
                int jj=j;
                if(jj>=N) jj-=N;
                if(A[ii][jj]!=A[(ii/M)*M][(jj/M)*M]) ok=false;
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(ok){
            ans=M;
            break;
        }
    }
    
    cout<<ans<<endl;
}