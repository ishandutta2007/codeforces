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
const int mod=1000000007,MAX=1000005,INF=1<<30;

int x[MAX],y[MAX];

int cnt[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int i=1000;i>=1;i--){
        for(int j=i*i;j<=1000000;j+=i*i){
            if(chmax(y[j],i)){
                x[j]=j/(i*i);
            }
        }
    }
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            cnt[x[A[i]]]++;
        }
        
        int ans0=0,ans1=0;
        
        for(int i=0;i<N;i++) chmax(ans0,cnt[x[A[i]]]);
        chmax(ans0,cnt[1]);
        
        for(int i=0;i<N;i++){
            if(x[A[i]]==1) continue;
            if(cnt[x[A[i]]]%2==0){
                cnt[1]+=cnt[x[A[i]]];
                cnt[x[A[i]]]=0;
            }
        }
        
        for(int i=0;i<N;i++) chmax(ans1,cnt[x[A[i]]]);
        chmax(ans1,cnt[1]);
        
        int Q;cin>>Q;
        while(Q--){
            ll w;cin>>w;
            if(w==0) cout<<ans0<<"\n";
            else cout<<ans1<<"\n";
        }
        
        for(int i=0;i<N;i++) cnt[x[A[i]]]=0;
        cnt[1]=0;
    }
}