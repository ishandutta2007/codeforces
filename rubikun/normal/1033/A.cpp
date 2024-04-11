#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

bool ng[MAX][MAX],can[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    int ax,ay,bx,by,cx,cy;cin>>ax>>ay>>bx>>by>>cx>>cy;
    ax--;ay--;
    bx--;by--;
    cx--;cy--;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==ax||j==ay||i+j==ax+ay||i-j==ax-ay) ng[i][j]=1;
        }
    }
    
    can[bx][by]=1;
    
    queue<pair<int,int>> Q;
    Q.push(mp(bx,by));
    
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        for(int dh=-1;dh<=1;dh++){
            for(int dw=-1;dw<=1;dw++){
                if(dh==0&&dw==0) continue;
                int toh=u.fi+dh,tow=u.se+dw;
                if(toh<0||toh>=N||tow<0||tow>=N) continue;
                if(ng[toh][tow]) continue;
                if(can[toh][tow]) continue;
                can[toh][tow]=1;
                Q.push(mp(toh,tow));
            }
        }
    }
    
    if(can[cx][cy]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}