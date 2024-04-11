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

bool compare(ll a,ll b,ll p,ll q){
    if(a*q>b*p) return true;
    else return false;
}
// a/b>p/qtrue

bool ok[4005][5][6];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<int>> A(N,vector<int>(5));
    vector<ll> cnt(5);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cin>>A[i][j];
            if(A[i][j]==-1) A[i][j]=250;
            else cnt[j]++;
        }
    }
    
    int ans=INF;
    
    vector<ll> score={500,1000,1500,2000,2500,3000},p={1,1,1,1,1,-1},q={2,4,8,16,32,1};
    
    for(int j=0;j<5;j++){
        for(int b=0;b<=3840;b++){
            for(int a=0;a<=b;a++){
                if(A[0][j]==250&&a) break;
                
                for(int i=0;i<5;i++){
                    if(compare(cnt[j]+a,N+b,p[i],q[i])){
                        ok[b][j][i]=1;
                        break;
                    }
                    if(i==4) ok[b][j][5]=1;
                }
            }
        }
    }
    
    for(int bit=0;bit<7776;bit++){
        int sa=bit;
        vector<int> T(5);
        for(int j=0;j<5;j++){
            T[j]=bit%6;
            bit/=6;
        }
        bit=sa;
        
        int sum=0;
        for(int j=0;j<5;j++){
            sum+=score[T[j]]*(A[1][j]-A[0][j])/250;
        }
        if(sum<=0) continue;
        
        int ma=INF;
        
        for(int i=0;i<=3840;i++){
            bool flag=true;
            for(int j=0;j<5;j++){
                if(!ok[i][j][T[j]]) flag=false;
            }
            if(flag){
                ma=i;
                break;
            }
        }
        
        chmin(ans,ma);
    }
    
    if(ans==INF) ans=-1;
    
    cout<<ans<<"\n";
}