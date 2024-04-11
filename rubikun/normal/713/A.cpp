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
    vector<int> cn((1<<18));
    while(Q--){
        char c;cin>>c;
        if(c=='+'){
            ll x;cin>>x;
            int S=0,t=0;
            while(x){
                if(x%2) S|=(1<<t);
                x/=10;
                t++;
            }
            cn[S]++;
        }else if(c=='-'){
            ll x;cin>>x;
            int S=0,t=0;
            while(x){
                if(x%2) S|=(1<<t);
                x/=10;
                t++;
            }
            cn[S]--;
        }else{
            string S;cin>>S;
            reverse(all(S));
            int T=0;
            for(int i=0;i<si(S);i++){
                if(S[i]=='1') T|=(1<<i);
            }
            cout<<cn[T]<<"\n";
        }
    }
}