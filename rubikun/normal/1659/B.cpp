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
const int mod=998244353,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        string S;cin>>S;
        for(int i=0;i<N;i++){
            if(K&1){
                if(S[i]=='0') S[i]='1';
                else S[i]='0';
            }
        }
        vector<int> ans(N);
        for(int i=0;i<N;i++){
            if(K==0) break;
            if(S[i]=='0'){
                S[i]='1';
                K--;
                ans[i]++;
            }
        }
        ans.back()+=K;
        if(K&1){
            if(S[N-1]=='0') S[N-1]='1';
            else S[N-1]='0';
        }
        
        cout<<S<<"\n";
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
    }
}