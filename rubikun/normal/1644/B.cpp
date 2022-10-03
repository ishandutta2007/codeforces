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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        set<vector<int>> SE;
        while(si(SE)<N){
            vector<int> A(N);iota(all(A),1);
            for(int q=0;q<100;q++){
                int x=rng()%N,y=rng()%N;
                swap(A[x],A[y]);
            }
            bool f=true;
            for(int i=2;i<N;i++) f&=(A[i-2]+A[i-1]!=A[i]);
            if(f) SE.insert(A);
        }
        for(auto a:SE){
            for(int x:a) cout<<x<<" ";
            cout<<"\n";
        }
    }
}