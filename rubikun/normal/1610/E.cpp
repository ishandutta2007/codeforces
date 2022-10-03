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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        A.push_back(INF);
        int ans=0;
        int s=0;
        while(s<N){
            int t=s;
            while(t<N&&A[s]==A[t]) t++;
            int cnt=t-s;
            if(t==N){
                chmax(ans,cnt);
                break;
            }
            cnt++;
            if(cnt+33>ans){
                int now=t;
                while(1){
                    auto it=lower_bound(all(A),A[now]-A[s]+A[now]);
                    if((*it)==INF) break;
                    cnt++;
                    now=it-A.begin();
                }
                chmax(ans,cnt);
            }
            
            s=t;
        }
        
        cout<<N-ans<<"\n";
    }
}