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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,L,R;cin>>N>>L>>R;
        multiset<int> SL,SR;
        
        for(int i=0;i<L;i++){
            int a;cin>>a;
            SL.insert(a);
        }
        
        for(int i=0;i<R;i++){
            int a;cin>>a;
            if(SL.count(a)){
                auto it=SL.lower_bound(a);
                SL.erase(it);
            }else{
                SR.insert(a);
            }
        }
        
        if(L>R){
            swap(SL,SR);
        }
        
        L=si(SL);
        R=si(SR);
        
        if(L==R){
            cout<<L<<"\n";
        }else{
            vector<int> cnt(N+1);
            for(auto a:SR){
                cnt[a]++;
            }
            
            int ans=0;
            
            for(int i=1;i<=N;i++){
                while(cnt[i]>=2&&L<R){
                    ans++;
                    cnt[i]-=2;
                    R-=2;
                }
            }
            
            ans+=(R-L)/2;
            ans+=(L+R)/2;
            
            cout<<ans<<"\n";
        }
    }
}