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
    
    int N;cin>>N;
    vector<int> aru(1005);
    for(int i=0;i<N;i++){
        int x;cin>>x;
        aru[x]=1;
    }
    for(int i=1;i<=1000;i++){
        if(aru[i]&&aru[i+1]&&aru[i+2]){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}