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
    string S;cin>>S;
    map<char,int> MA;
    for(char c:S){
        MA[c]++;
    }
    int ma=-1,cn=0;
    for(auto a:MA){
        if(chmax(ma,a.se)){
            cn=1;
        }else if(ma==a.se){
            cn++;
        }
    }
    
    ll ans=1;
    
    for(int i=0;i<N;i++){
        ans*=cn;
        ans%=mod;
    }
    
    cout<<ans<<endl;
}