#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

vector<int> dx={0,1,0,-1},dy={1,0,-1,0};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,sx,sy;cin>>N>>sx>>sy;
    
    vector<int> x(N),y(N);
    for(int i=0;i<N;i++) cin>>x[i]>>y[i];
    
    int ma=0,gx=sx,gy=sy;
    
    for(int k=0;k<4;k++){
        if(sx+dx[k]<0||sx+dx[k]>1000000000||sy+dy[k]<0||sy+dy[k]>1000000000) continue;
        int cnt=0;
        
        for(int i=0;i<N;i++){
            if(k==0){
                if(y[i]>sy) cnt++;
            }else if(k==1){
                if(x[i]>sx) cnt++;
            }else if(k==2){
                if(y[i]<sy) cnt++;
            }else{
                if(x[i]<sx) cnt++;
            }
        }
        
        if(ma<cnt){
            ma=cnt;
            gx=sx+dx[k];
            gy=sy+dy[k];
        }
    }
    
    cout<<ma<<endl;
    cout<<gx<<" "<<gy<<endl;
}