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
const int mod=1000000007,MAX=1000005,INF=1<<30;

vector<int> X[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<N;i++){
        int x;cin>>x;
        for(int j=0;j<x;j++){
            int k;cin>>k;k--;
            X[k].push_back(i);
        }
    }
    
    map<vector<int>,int> MA;
    for(int i=0;i<M;i++){
        MA[X[i]]++;
    }
    
    ll ans=1;
    
    for(auto a:MA){
        for(int j=a.se;j>=1;j--){
            ans*=j;
            ans%=mod;
        }
    }
    
    cout<<ans<<endl;
}