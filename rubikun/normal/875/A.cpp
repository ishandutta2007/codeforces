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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> ans;
    
    for(int i=max(1,N-200);i<=N;i++){
        int sum=i;
        int now=i;
        while(now){
            sum+=now%10;
            now/=10;
        }
        if(sum==N) ans.push_back(i);
    }
    cout<<si(ans)<<endl;
    for(int a:ans) cout<<a<<" ";
    cout<<endl;
}