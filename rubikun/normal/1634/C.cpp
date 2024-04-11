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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        if(N%2==0||K==1){
            cout<<"YES\n";
            vector<vector<int>> ans(N,vector<int>(K));
            int now=1;
            for(int j=0;j<K;j++){
                for(int i=0;i<N;i++){
                    ans[i][j]=now;
                    now++;
                }
            }
            for(int i=0;i<N;i++){
                for(int j=0;j<K;j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<"\n";
            }
        }else{
            cout<<"NO\n";
        }
    }
}