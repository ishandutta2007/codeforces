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
const int mod=998244353,MAX=300005,INF=1<<30;

vector<pair<int,int>> use;
vector<int> ho[1<<16];
vector<int> ma;
int dp[2][1<<16];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int N,K;cin>>N>>K;
    vector<int> P(N),pos(N),mask(N);
    for(int i=0;i<N;i++){
        cin>>P[i];P[i]--;
        pos[P[i]]=i;
    }
    
    ll sum=0;
    
    for(int x=0;x<N;x++){
        for(int a=0;a<x-2*K;a++){
            if(pos[a]>pos[x]) sum++;
        }
        for(int a=x-2*K;a<=x+K;a++){
            if(a>=0&&a<N){
                if(pos[a]>pos[x]) mask[x]|=(1<<(a-(x-2*K)));
            }
        }
    }
    
    for(int bit=0;bit<(1<<(2*K));bit++){
        if(__builtin_popcount(bit)==K){
            use.push_back(mp(bit,-1));
            for(int j=2*K-1;j>=0;j--){
                if(bit&(1<<j)){
                    use.back().se=j;
                    break;
                }
            }
            int mi=INF;
            for(int j=0;j<2*K;j++){
                if(!(bit&(1<<j))){
                    mi=j;
                    break;
                }
            }
            if(use.back().se-mi>K){
                use.pop_back();
                continue;
            }
            for(int j=0;j<2*K;j++){
                if(!(bit&(1<<j))){
                    if(use.back().se-K-(j-K)>K) continue;
                    if(!(bit&1)){
                        if(j) continue;
                    }
                    ho[bit].push_back(j-K);
                }
            }
            ho[bit].push_back(K);
        }
    }
    
    for(int i=0;i<2;i++) for(int j=0;j<(1<<16);j++) dp[i][j]=INF;
    
    dp[0][use[0].fi]=0;
    
    //for(auto [j,ma]:use) cout<<j<<" "<<ma<<endl;
    
    for(int i=0;i<N;i++){
        int s=i&1,t=s^1;
        for(auto [j,ma]:use){
            if(dp[s][j]<INF){
                int x=dp[s][j];
                for(int k:ho[j]){
                    if(i+k<0||i+k>=N) continue;
                    if(k<K){
                        if(j&(1<<(k+K))) continue;
                    }
                    //if((ma-K)-k>K) continue;
                    int nex=j|(1<<(k+K));
                    if(!(nex&1)) continue;
                    int cost=x;
                    
                    int zz=(j<<(K-k))|((1<<(K-k))-1);
                    cost+=__builtin_popcount(zz&mask[i+k]);
                    /*
                    for(int a=i+k-2*K;a<=i+k+K;a++){
                        int z=a-i+K;
                        if(a>=0&&a<N){
                            if(((z<0)||(j&(1<<z)))&&pos[a]>pos[i+k]) cost++;
                        }
                    }
                    */
                    chmin(dp[t][nex>>1],cost);
                    //cout<<s<<" "<<j<<" "<<x<<" "<<k<<" "<<t<<" "<<(nex>>1)<<" "<<cost<<endl;
                }
            }
            
            dp[s][j]=INF;
        }
    }
    
    cout<<dp[(N&1)][use[0].fi]+sum<<endl;
}