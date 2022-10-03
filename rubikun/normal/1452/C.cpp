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
const int mod=1000000007,MAX=100005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int ans=0;
        int N=si(S);
        int i=0,j=0;
        while(i<N){
            while(i<N&&S[i]!='(') i++;
            if(i==N) break;
            while(j<i) j++;
            while(j<N&&S[j]!=')') j++;
            if(j==N) break;
            ans++;
            i++;
            j++;
        }
        
        i=0;j=0;
        
        while(i<N){
            while(i<N&&S[i]!='[') i++;
            if(i==N) break;
            while(j<i) j++;
            while(j<N&&S[j]!=']') j++;
            if(j==N) break;
            ans++;
            i++;
            j++;
        }
        
        cout<<ans<<"\n";
    }
}