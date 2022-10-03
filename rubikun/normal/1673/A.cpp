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
        string S;cin>>S;
        int N=si(S);
        if(N%2==0){
            ll ans=0;
            for(char c:S){
                ans+=(c-'a')+1;
            }
            cout<<"Alice "<<ans<<"\n";
        }else{
            ll ans=0;
            if(S[0]>S.back()){
                for(int i=0;i<N-1;i++){
                    ans+=(S[i]-'a')+1;
                }
                ans-=(S.back()-'a')+1;
            }else{
                for(int i=1;i<N;i++){
                    ans+=(S[i]-'a')+1;
                }
                ans-=(S[0]-'a')+1;
            }
            if(ans>0) cout<<"Alice "<<ans<<"\n";
            else cout<<"Bob "<<-ans<<"\n";
        }
    }
}