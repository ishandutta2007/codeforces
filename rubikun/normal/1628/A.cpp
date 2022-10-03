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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<61;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),cnt(N+1),deta(N+1);
        for(int i=0;i<N;i++){
            cin>>A[i];
            cnt[A[i]]++;
        }
        int mi=-1;
        for(int i=0;i<=N;i++){
            if(cnt[i]==0){
                mi=i;
                break;
            }
        }
        vector<int> ans;
        int s=0;
        while(s<N){
            int t=s;
            int cn=0,nex=mi;
            while(t<N){
                if(A[t]<mi&&deta[A[t]]==0) cn++;
                deta[A[t]]=1;
                cnt[A[t]]--;
                if(cnt[A[t]]==0) chmin(nex,A[t]);
                t++;
                if(cn>=mi) break;
            }
            ans.push_back(mi);
            for(int k=s;k<t;k++) deta[A[k]]=0;
            s=t;
            mi=nex;
        }
        
        cout<<si(ans)<<"\n";
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
    }
}