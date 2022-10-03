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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> cn(100005);
    for(int i=0;i<N;i++){
        int x;cin>>x;
        cn[x]++;
    }
    int ans=1;
    
    for(int i=2;i<=100000;i++){
        int sum=0;
        for(int j=i;j<=100000;j+=i){
            sum+=cn[j];
        }
        chmax(ans,sum);
    }
    
    cout<<ans<<endl;
}