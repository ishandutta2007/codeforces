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
const int mod=1000000007,MAX=200005;
const int INF=1<<30;
int cnt[MAX],sum[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,s;cin>>N>>s;
    s--;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    if(N==1){
        if(A[0]==0) cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    
    int ans=INF;
    
    for(int i=0;i<N;i++){
        if(i==s) continue;
        cnt[A[i]]++;
    }
    for(int i=1;i<=N;i++) sum[i]=cnt[i]+sum[i-1];
    int no=0;
    for(int i=1;i<N;i++){
        if(cnt[i]==0) no++;
        chmin(ans,max(N-1-sum[i],no));
    }
    
    if(A[s]) ans++;
    
    cout<<ans<<endl;
}