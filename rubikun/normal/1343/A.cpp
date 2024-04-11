#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    vector<ll> A={4};
    while(A.back()<=1000000000) A.push_back(A.back()*2);
    for(int i=0;i<A.size();i++) A[i]--;
    
    while(Q--){
        ll N;cin>>N;
        for(ll a:A){
            if(N%a==0){
                cout<<N/a<<"\n";
                break;
            }
        }
    }
}