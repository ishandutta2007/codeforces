#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=103,INF=1<<29;
int S[MAX][MAX],dis[MAX][MAX],N;

void floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin>>N;
    for(int i=0;i<N;i++){
        string a;cin>>a;
        for(int j=0;j<N;j++){
            dis[i][j]=INF;
            if(i==j) dis[i][j]=0;
            S[i][j]=a[j]-'0';
            if(S[i][j]) dis[i][j]=S[i][j];
        }
    }
    
    floyd();
    
    int M;cin>>M;
    vector<int> A(M),B;
    for(int i=0;i<M;i++){
        cin>>A[i];
        A[i]--;
    }
    
    B.push_back(A[0]);
    
    int s=0,t=1,cnt=1;
    while(1){
        while(t<M&&t-s<=dis[A[s]][A[t]]){
            t++;
        }
        t--;
        cnt++;
        B.push_back(A[t]);
        s=t;
        t++;
        if(s==M-1) break;
    }
    
    cout<<cnt<<endl;
    for(int i=0;i<B.size();i++){
        if(i) cout<<" ";
        cout<<B[i]+1;
    }
    
    cout<<endl;
}