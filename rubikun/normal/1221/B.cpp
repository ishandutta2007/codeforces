#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=105,INF=1<<30;
char S[MAX][MAX];
int visited[MAX][MAX],N;

vector<int> dx={-2,-2,-1,-1,1,1,2,2},dy={1,-1,2,-2,2,-2,1,-1};

void DFS(int h,int w){
    for(int i=0;i<8;i++){
        int hh=h+dx[i],ww=w+dy[i];
        if(hh<0||hh>=N||ww<0||ww>=N) continue;
        if(visited[hh][ww]) continue;
        visited[hh][ww]=1;
        if(S[h][w]=='W') S[hh][ww]='B';
        else S[hh][ww]='W';
        DFS(hh,ww);
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            S[i][j]='W';
            visited[i][j]=0;
        }
    }
    
    visited[0][0]=1;
    
    DFS(0,0);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<S[i][j];
        }
        cout<<endl;
    }
}