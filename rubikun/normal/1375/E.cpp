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
    
    int N;cin>>N;
    vector<int> A(N);
    vector<pair<int,int>> ans;
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int t=N-1;t>=0;t--){
        vector<pair<int,int>> X;
        for(int i=0;i<t;i++){
            if(A[i]>A[t]){
                X.push_back(mp(A[i],i));
            }
        }
        sort(all(X));
        
        for(auto x:X){
            ans.push_back(mp(x.se,t));
            //swap(A[x.se],A[t]);
        }
    }
    
    cout<<si(ans)<<endl;
    for(auto x:ans) cout<<x.fi+1<<" "<<x.se+1<<endl;
}