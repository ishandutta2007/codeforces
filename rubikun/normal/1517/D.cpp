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
const int mod=1000000007,MAX=250005,INF=1<<29;

pair<int,int> G[MAX][4];

bool seen[10][MAX];
int dis[10][MAX];
int mi[MAX];

vector<pair<int,int>> mov[MAX];

int H,W;
int f(int a,int b){
    return a*W+b;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int K;cin>>H>>W>>K;
    if(K&1){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout<<-1<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }
    
    K/=2;
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<4;j++) G[i][j]=mp(-1,-1);
        mi[i]=INF;
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j+1<W;j++){
            int x;cin>>x;
            G[f(i,j)][0]=mp(f(i,j+1),x);
            G[f(i,j+1)][1]=mp(f(i,j),x);
            //G[i][j].push_back(mp(mp(i,j+1),x));
            //G[i][j+1].push_back(mp(mp(i,j),x));
            chmin(mi[f(i,j)],x);
            chmin(mi[f(i,j+1)],x);
        }
    }
    
    for(int i=0;i+1<H;i++){
        for(int j=0;j<W;j++){
            int x;cin>>x;
            G[f(i,j)][2]=mp(f(i+1,j),x);
            G[f(i+1,j)][3]=mp(f(i,j),x);
            //G[i][j].push_back(mp(mp(i+1,j),x));
            //G[i+1][j].push_back(mp(mp(i,j),x));
            chmin(mi[f(i,j)],x);
            chmin(mi[f(i+1,j)],x);
        }
    }
    
    for(int h=-K;h<=K;h++){
        for(int w=-K;w<=K;w++){
            int d=abs(h)+abs(w);
            for(int t=d;t<=K;t+=2) mov[t].push_back(mp(h,w));
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int t=0;t<K;t++){
                for(auto d:mov[t]){
                    int h=i+d.fi,w=j+d.se;
                    if(h<0||h>=H||w<0||w>=W) continue;
                    dis[t][f(h,w)]=INF;
                    seen[t][f(h,w)]=0;
                }
            }
            dis[0][f(i,j)]=0;
            seen[0][f(i,j)]=1;
            //dis[0][i][j]=0;
            //seen[0][i][j]=1;
            queue<pair<int,int>> Q;
            Q.push(mp(f(i,j),0));
            
            while(!Q.empty()){
                auto u=Q.front();Q.pop();
                //if(u.se==K) break;
                
                for(int t=0;t<4;t++){
                    auto to=G[u.fi][t];
                    if(to.fi==-1) continue;
                    chmin(dis[u.se+1][to.fi],dis[u.se][u.fi]+to.se);
                    
                    if(u.se+1>=K-1) continue;
                    if(!seen[u.se+1][to.fi]){
                        seen[u.se+1][to.fi]=true;
                        Q.push(mp(to.fi,u.se+1));
                    }
                }
            }
            
            int ans=INF;
            
            for(int h=i-K;h<=i+K;h++){
                for(int w=j-K;w<=j+K;w++){
                    if(h<0||h>=H||w<0||w>=W) continue;
                    int d=abs(h-i)+abs(w-j)+K-1;
                    if(d>2*(K-1)) continue;
                    d&=1;
                    if((!d)) chmin(ans,dis[K-1][f(h,w)]+mi[f(h,w)]);
                }
            }
            
            cout<<ans*2<<" ";
        }
        cout<<"\n";
    }
}