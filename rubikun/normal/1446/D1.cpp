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
const int mod=1000000007,MAX=200005,INF=1<<30;

int cnt[MAX][105],wh[MAX][105];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    vector<int> use;
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]--;
        use.push_back(A[i]);
    }
    sort(all(use));
    use.erase(unique(all(use)),use.end());
    for(int i=0;i<N;i++){
        //int x=lower_bound(all(use),A[i])-use.begin();
        //A[i]=x;
        cnt[i+1][A[i]]++;
    }
    int M=100;
    
    if(M==1){
        cout<<0<<endl;
        return 0;
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    
    for(int i=0;i<MAX;i++) for(int j=0;j<M;j++) wh[i][j]=INF;
    
    for(int i=N;i>=0;i--){
        for(int j=0;j<M;j++){
            chmin(wh[cnt[i][j]][j],i);
        }
    }
    
    int ans=0;
    
    for(int i=0;i<N;i++){
        if(N-i<=ans) break;
        pair<int,int> ma1=mp(-INF,-INF),ma2=mp(-INF,-INF);
        for(int j=0;j<M;j++){
            if(ma1.fi<cnt[N][j]-cnt[i][j]){
                ma2=ma1;
                ma1=mp(cnt[N][j]-cnt[i][j],j);
            }else if(ma2.fi<cnt[N][j]-cnt[i][j]){
                ma2=mp(cnt[N][j]-cnt[i][j],j);
            }
        }
        
        if(ma1.fi==ma2.fi){
            chmax(ans,N-i);
            continue;
        }
        
        //cout<<ma1.fi<<" "<<ma1.se<<endl;
        //cout<<ma2.fi<<" "<<ma2.se<<endl;
        
        while(1){
            int r=wh[cnt[i][ma1.se]+ma2.fi+1][ma1.se];
            if(r==INF) break;
            r--;
            if(r<=i+1) break;
            
            if(r-i<=ans) break;
            
            //cout<<r<<endl;
            
            ma1=mp(-INF,-INF);
            ma2=mp(-INF,-INF);
            
            for(int j=0;j<M;j++){
                if(ma1.fi<cnt[r][j]-cnt[i][j]){
                    ma2=ma1;
                    ma1=mp(cnt[r][j]-cnt[i][j],j);
                }else if(ma2.fi<cnt[r][j]-cnt[i][j]){
                    ma2=mp(cnt[r][j]-cnt[i][j],j);
                }
            }
            
            if(ma1.fi==ma2.fi){
                chmax(ans,r-i);
                break;
            }
        }
    }
    
    cout<<ans<<endl;
    
    
}