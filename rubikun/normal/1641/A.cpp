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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll X;cin>>N>>X;
        set<pair<ll,int>> SE;
        vector<ll> A(N);
        for(int i=0;i<N;i++){
            ll x;cin>>x;
            A[i]=x;
        }
        sort(all(A));
        for(int i=0;i<N;i++){
            SE.insert(mp(A[i],i));
        }
        for(int i=0;i<N;i++){
            if(!SE.count(mp(A[i],i))) continue;
            auto it=SE.lower_bound(mp(A[i]*X,-1));
            if(it!=SE.end()&&(*it).fi==A[i]*X){
                SE.erase(it);
                SE.erase(mp(A[i],i));
            }
        }
        
        cout<<si(SE)<<"\n";
    }
}