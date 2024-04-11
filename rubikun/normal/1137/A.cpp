#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<vector<int>> A(N,vector<int>(M)),B(N,vector<int>(M));
    vector<int> maxiA(N),maxiB(M);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
            B[i][j]=A[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        map<int,int> MA;
        for(int j=0;j<M;j++){
            MA[A[i][j]]++;
        }
        int cnt=1;
        for(auto it=MA.begin();it!=MA.end();it++){
            MA[(*it).first]=cnt;
            cnt++;
        }
        maxiA[i]=cnt-1;
        
        for(int j=0;j<M;j++){
            A[i][j]=MA[A[i][j]];
        }
    }
    
    for(int j=0;j<M;j++){
        map<int,int> MA;
        for(int i=0;i<N;i++){
            MA[B[i][j]]++;
        }
        int cnt=1;
        for(auto it=MA.begin();it!=MA.end();it++){
            MA[(*it).first]=cnt;
            cnt++;
        }
        maxiB[j]=cnt-1;
        
        for(int i=0;i<N;i++){
            B[i][j]=MA[B[i][j]];
        }
    }
    
    vector<vector<int>> ans(N,vector<int>(M));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int cnt1=0,cnt2=0;
            cnt1=max(cnt1,A[i][j]-1);cnt2=max(cnt2,maxiA[i]-A[i][j]);
            cnt1=max(cnt1,B[i][j]-1);cnt2=max(cnt2,maxiB[j]-B[i][j]);
            
            ans[i][j]=cnt1+cnt2+1;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}