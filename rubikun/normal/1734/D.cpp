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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        int K;cin>>K;K--;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int now=K;
        vector<pair<int,pair<ll,ll>>> left(N),right(N);
        while(1){
            int j=now+1;
            ll sum=0,mi=1LL<<60;
            while(j<N){
                sum+=A[j];
                chmin(mi,sum);
                if(sum>=0){
                    right[now]=mp(j,mp(sum,mi));
                    break;
                }else{
                    j++;
                }
            }
            if(j==N){
                right[now]=mp(N,mp(sum,mi));
                break;
            }else{
                now=j;
            }
        }
        now=K;
        while(1){
            int j=now-1;
            ll sum=0,mi=1LL<<60;
            while(j>=0){
                sum+=A[j];
                chmin(mi,sum);
                if(sum>=0){
                    left[now]=mp(j,mp(sum,mi));
                    break;
                }else{
                    j--;
                }
            }
            if(j==-1){
                left[now]=mp(-1,mp(sum,mi));
                break;
            }else{
                now=j;
            }
        }
        
        int L=K,R=K;
        ll sum=A[K];
        
        bool ans=true;
        while(L>=0&&R<N){
            if(sum+left[L].se.se>=0){
                sum+=left[L].se.fi;
                L=left[L].fi;
            }else if(sum+right[R].se.se>=0){
                sum+=right[R].se.fi;
                R=right[R].fi;
            }else{
                ans=false;
                break;
            }
        }
        
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}