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
const int mod=1000000007,MAX=100005,INF=1<<30;

ll pre[13][70][1<<10];
ll dp[20][1<<10];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int B=2;B<=10;B++){
        pre[B][0][0]=1;
        ll lim=1;
        for(int i=0;i<70;i++){
            for(int j=0;j<(1<<B);j++){
                for(int k=0;k<B;k++){
                    pre[B][i+1][j^(1<<k)]+=pre[B][i][j];
                }
            }
            if(lim>=(ll)(4e18)/B) break;
            lim*=B;
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        int B;ll L,R;cin>>B>>L>>R;
        auto f=[&](ll X){
            vector<int> S;
            ll rem=X;
            while(rem){
                S.push_back(rem%B);
                rem/=B;
            }
            reverse(all(S));
            ll res=0;
            
            for(int len=2;len<=si(S);len+=2){
                if(len==si(S)){
                    for(int i=0;i<=len;i++){
                        int T=0;
                        for(int j=0;j<i;j++) T^=(1<<S[si(S)-len+j]);
                        if(i==len){
                            if(T==0) res++;
                        }else{
                            for(int k=0;k<S[si(S)-len+i];k++){
                                if(k||i) res+=pre[B][len-i-1][T^(1<<k)];
                            }
                        }
                    }
                }else{
                    for(int k=1;k<B;k++){
                        res+=pre[B][len-1][(1<<k)];
                    }
                }
            }
            
            return res;
        };
        //cout<<f(R)<<" "<<f(L-1)<<"\n";
        cout<<f(R)-f(L-1)<<"\n";
    }
}