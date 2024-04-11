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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        int ans=0;
        int i=0;
        while(i<N){
            while(i<N&&S[i]=='1') i++;
            if(i==N) break;
            int j=i+1;
            while(j<N&&S[j]=='1') j++;
            if(j==N) break;
            ans+=max(0,2-(j-i-1));
            i=j;
        }
        cout<<ans<<"\n";
    }
}