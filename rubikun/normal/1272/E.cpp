#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300005,INF=1<<30;
int N;
int odddis[MAX],evendis[MAX],A[MAX];
vector<int> G[MAX];

void oddBFS(){
    queue<int> Q;
    for(int i=0;i<N;i++){
        if(A[i]%2==1){
            Q.push(i);
            odddis[i]=0;
        }
    }
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(int j=0;j<G[a].size();j++){
            int b=G[a][j];
            if(odddis[b]==INF){
                Q.push(b);
                odddis[b]=odddis[a]+1;
            }
        }
        /*if(a-A[a]>=0&&odddis[a-A[a]]==INF){
            Q.push(a-A[a]);
            odddis[a-A[a]]=odddis[a]+1;
        }
        if(a+A[a]<N&&odddis[a+A[a]]==INF){
            Q.push(a+A[a]);
            odddis[a+A[a]]=odddis[a]+1;
        }*/
    }
}

void evenBFS(){
    queue<int> Q;
    for(int i=0;i<N;i++){
        if(A[i]%2==0){
            Q.push(i);
            evendis[i]=0;
        }
    }
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(int j=0;j<G[a].size();j++){
            int b=G[a][j];
            if(evendis[b]==INF){
                Q.push(b);
                evendis[b]=evendis[a]+1;
            }
        }
        /*if(a-A[a]>=0&&evendis[a-A[a]]==INF){
            Q.push(a-A[a]);
            evendis[a-A[a]]=evendis[a]+1;
        }
        if(a+A[a]<N&&evendis[a+A[a]]==INF){
            Q.push(a+A[a]);
            evendis[a+A[a]]=evendis[a]+1;
        }*/
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        odddis[i]=INF;
        evendis[i]=INF;
        if(i-A[i]>=0) G[i-A[i]].push_back(i);
        if(i+A[i]<N) G[i+A[i]].push_back(i);
    }
    
    oddBFS();
    evenBFS();
    
    for(int i=0;i<N;i++){
        if(A[i]%2==0){
            if(odddis[i]==INF) cout<<-1<<" ";
            else cout<<odddis[i]<<" ";
        }else{
            if(evendis[i]==INF) cout<<-1<<" ";
            else cout<<evendis[i]<<" ";
        }
    }
    
    cout<<endl;
    
}