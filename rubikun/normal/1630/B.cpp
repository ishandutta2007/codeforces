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

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        vector<int> A(N),cnt(N+1);
        for(int i=0;i<N;i++){
            cin>>A[i];
            cnt[A[i]]++;
        }
        for(int i=1;i<=N;i++) cnt[i]+=cnt[i-1];
        
        pair<int,int> ans=mp(INF,INF);
        int need=(N+K+1)/2;
        
        for(int l=1;l<=N;l++){
            auto it=lower_bound(all(cnt),cnt[l-1]+need);
            if(it==cnt.end()) continue;
            int r=it-cnt.begin();
            chmin(ans,mp(r-l,l));
        }
        
        //cout<<ans.se<<" "<<ans.fi+ans.se<<"\n";
        int l=ans.se,r=ans.fi+ans.se;
        cout<<l<<" "<<r<<"\n";
        vector<pair<int,int>> res;
        int i=0;
        while(i<N){
            if(si(res)+1==K){
                res.push_back(mp(i,N-1));
                break;
            }
            int j=i,cn=0;
            while(j<N&&cn<=0){
                if(l<=A[j]&&A[j]<=r) cn++;
                else cn--;
                j++;
            }
            res.push_back(mp(i,j-1));
            i=j;
        }
        for(auto a:res) cout<<a.fi+1<<" "<<a.se+1<<"\n";
    }
    
}