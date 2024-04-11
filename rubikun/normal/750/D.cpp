#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=605,INF=1<<30;
int d[35],N;
bool use[MAX][MAX][8][35];
bool visit[MAX][MAX];

vector<int> dh={-1,-1,0,1,1,1,0,-1},dw={0,1,1,1,0,-1,-1,-1};

void DFS(pair<int,int> u,int dir,int turn){
    if(turn==N) return;
    int hnow=u.first,wnow=u.second;
    visit[hnow][wnow]=1;
    for(int i=0;i<d[turn];i++){
        hnow+=dh[dir];
        wnow+=dw[dir];
        
        visit[hnow][wnow]=1;
    }
    if(use[hnow][wnow][(dir+7)%8][turn+1]==0){
        use[hnow][wnow][(dir+7)%8][turn+1]=1;
        DFS({hnow,wnow},(dir+7)%8,turn+1);
    }
    
    if(use[hnow][wnow][(dir+1)%8][turn+1]==0){
        use[hnow][wnow][(dir+1)%8][turn+1]=1;
        DFS({hnow,wnow},(dir+1)%8,turn+1);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>d[i];
    d[0]--;
    
    use[300][300][0][0]=1;
    visit[300][300]=1;

    DFS({300,300},0,0);
    
    int cnt=0;
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(visit[i][j]) cnt++;
        }
    }
    
    cout<<cnt<<endl;
}