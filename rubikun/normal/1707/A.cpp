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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            int x;cin>>x;
            chmin(x,N+1);
            A[i]=x;
        }
        if(K>=N){
            for(int i=0;i<N;i++) cout<<1;
            cout<<"\n";
            continue;
        }
        
        string ans;
        int lim=0;
        
        for(int i=N-1;i>=0;i--){
            if(A[i]<=lim){
                ans+='1';
            }else{
                if(lim==K){
                    ans+='0';
                }else{
                    ans+='1';
                    lim++;
                }
            }
        }
        
        reverse(all(ans));
        cout<<ans<<"\n";
    }
}