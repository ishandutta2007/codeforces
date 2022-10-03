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
        string S,T;cin>>S>>T;
        if((si(S)&1)!=(si(T)&1)) S=S.substr(1);
        int i=-1,j=0;
        int N=si(S),M=si(T);
        bool ok=true;
        while(1){
            int k=i+1;
            while(k<N&&(S[k]!=T[j]||(abs(i+k)%2==0))) k++;
            if(k==N){
                ok=false;
                break;
            }
            i=k;
            j++;
            if(j==M) break;
        }
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}