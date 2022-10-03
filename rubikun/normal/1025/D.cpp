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
const int mod=1000000007,MAX=705,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int N;
int A[MAX];

bool dpl[MAX][MAX],dpr[MAX][MAX];

ll gc[MAX][MAX];

bool f(int i,int j){
    if(i<0||j<0||i>=N||j>=N) return 0;
    if(gc[i][j]==0) gc[i][j]=gcd(A[i],A[j]);
    return gc[i][j]>=2;
}

bool fl(int i,int j){
    if(i<0||j<0||i>=N||j>=N) return 0;
    return dpl[i][j];
}

bool fr(int i,int j){
    if(i<0||j<0||i>=N||j>=N) return 0;
    return dpr[i][j];
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i+1<N;i++){
        if(A[i]==A[i+1]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    for(int i=0;i<N;i++){
        dpl[i][i]=1;
        dpr[i][i]=1;
    }
    
    for(int t=0;t<N;t++){
        for(int l=0;l<=t;l++){
            int r=t-l;
            for(int i=0;i<N;i++){
                if(fl(i-l,i)&&fr(i+r,i)){
                    if(f(i,i-l-1)) dpr[i+r][i-l-1]=1;
                    if(f(i,i+r+1)) dpl[i-l][i+r+1]=1;
                }
            }
        }
    }
    
    bool ans=false;
    
    for(int i=0;i<N;i++) if(dpl[0][i]&&dpr[N-1][i]) ans=true;
    
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}