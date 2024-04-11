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
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<61;

const int M=100000;

bool seen[3005][3005];
int memo[3005][3005];

int gcd(int a,int b){
    if(b==0) return a;
    if(a<3000&&b<3000){
        if(seen[a][b]) return memo[a][b];
        seen[a][b]=true;
        return memo[a][b]=gcd(b,a%b);
    }else{
        return gcd(b,a%b);
    }
}

const int D=400;

ll hin[MAX],cnt[MAX];
ll S[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int d=1;d<=D;d++){
        memset(hin,0,sizeof(hin));
        memset(cnt,0,sizeof(cnt));
        for(int i=d;i<=N;i+=d){
            hin[A[i-1]]++;
        }
        for(int i=M;i>=1;i--){
            for(int j=i;j<=M;j+=i) cnt[i]+=hin[j];
            cnt[i]=cnt[i]*cnt[i];
            for(int j=2*i;j<=M;j+=i) cnt[i]-=cnt[j];
            S[d]+=cnt[i]*i;
        }
    }
    
    for(int d=D+1;d<=N;d++){
        ll sum=0;
        for(int i=d;i<=N;i+=d){
            for(int j=d;j<=N;j+=d){
                sum+=gcd(A[i-1],A[j-1]);
            }
        }
        S[d]=sum;
    }
    
    ll ans=0;
    
    for(int i=N;i>=1;i--){
        for(int j=2*i;j<=N;j+=i) S[i]-=S[j];
        ans+=(S[i]%mod)*i;
        ans%=mod;
    }
    
    cout<<ans<<endl;
}