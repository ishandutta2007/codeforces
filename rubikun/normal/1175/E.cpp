#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=500003,MAX_LOG=20,INF=1<<30;
int to[MAX][MAX_LOG];

void init(){
    for(int j=1;j<MAX_LOG;j++){
        for(int i=0;i<MAX;i++){
            if(to[i][j-1]<0) to[i][j]=-1;
            to[i][j]=max(to[i][j-1],to[to[i][j-1]][j-1]);
        }
    }
}

int query(int a,int b){
    int ans=0;
    for(int j=19;j>=0;j--){
        if(to[a][j]>=b) continue;
        ans|=(1<<j);
        a=to[a][j];
    }
    if(a<b) ans++;
    if(ans>=(1<<19)) return -1;
    return ans;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX_LOG;j++){
            to[i][j]=-1;
        }
    }
    
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        to[a][0]=max(to[a][0],b);
    }
    for(int i=1;i<MAX;i++){
        to[i][0]=max(to[i][0],to[i-1][0]);
    }
    
    init();
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        cout<<query(a,b)<<endl;
    }
    
}