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
const int mod=998244353,MAX=55,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> P(N);
        iota(all(P),1);
        vector<vector<int>> ans;
        ans.push_back(P);
        for(int i=0;i+1<N;i++){
            swap(P[i],P[i+1]);
            ans.push_back(P);
        }
        
        cout<<si(ans)<<"\n";
        for(auto a:ans){
            for(int b:a) cout<<b<<" ";
            cout<<"\n";
        }
    }
}