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
const ll INF=1LL<<60;

int ans[1<<12][105];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,Q;cin>>N>>M>>Q;
    vector<int> cnt(1<<N),w(N);
    for(int i=0;i<N;i++) cin>>w[i];
    for(int i=0;i<M;i++){
        string S;cin>>S;
        int x=0;
        for(int j=0;j<N;j++){
            if(S[j]=='1') x+=(1<<j);
        }
        cnt[x]++;
    }
    
    for(int q=0;q<(1<<N);q++){
        for(int i=0;i<(1<<N);i++){
            int sum=0;
            for(int j=0;j<N;j++){
                if((q&(1<<j))==(i&(1<<j))) sum+=w[j];
            }
            if(sum<=100){
                ans[q][sum]+=cnt[i];
            }
        }
    }
    
    for(int q=0;q<(1<<N);q++){
        for(int i=1;i<=100;i++){
            ans[q][i]+=ans[q][i-1];
        }
    }
    
    while(Q--){
        string A;int B;cin>>A>>B;
        int x=0;
        for(int j=0;j<N;j++){
            if(A[j]=='1') x+=(1<<j);
        }
        cout<<ans[x][B]<<"\n";
    }
}