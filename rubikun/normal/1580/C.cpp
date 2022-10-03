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
const int mod=1000000007,MAX=200005,INF=1<<29;

const int D=300;

int ad[MAX];

bool alive[MAX];

int A[D][D],B[D][D];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,M;cin>>N>>M;
    vector<ll> x(N),y(N);
    for(int i=0;i<N;i++) cin>>x[i]>>y[i];
    vector<ll> wh(N,-1);
    
    int sum=0;
    
    for(int t=1;t<=M;t++){
        int k,id;cin>>k>>id;id--;
        if(k==1){
            if(x[id]+y[id]>=D){
                ll now=t;
                while(now<=M){
                    now+=x[id];
                    if(now<=M) ad[now]++;
                    now+=y[id];
                    if(now<=M) ad[now]--;
                }
            }else{
                sum++;
                ll len=x[id]+y[id];
                A[len][(t+x[id])%len]++;
                B[len][t%len]++;
            }
            wh[id]=t;
        }else{
            if(x[id]+y[id]>=D){
                ll now=wh[id];
                while(now<=M){
                    now+=x[id];
                    if(now>=t&&now<=M) ad[now]--;
                    now+=y[id];
                    if(now>=t&&now<=M) ad[now]++;
                }
                ll st=(t-wh[id])%(x[id]+y[id]);
                if(st==0||st>x[id]) sum--;
            }else{
                //sum--;
                ll len=x[id]+y[id];
                A[len][(wh[id]+x[id])%len]--;
                B[len][wh[id]%len]--;
                
                ll st=(t-wh[id])%len;
                if(st==0||st>x[id]) sum--;
            }
            wh[id]=-1;
        }
        
        //cout<<sum<<endl;
        
        for(int i=1;i<D;i++){
            int x=t%i;
            sum+=A[i][x];
            sum-=B[i][x];
        }
        ad[t]+=ad[t-1];
        
        cout<<sum+ad[t]<<"\n";
    }
}