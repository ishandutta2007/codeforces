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
const int mod=1000000007,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll K,A,B;cin>>K>>A>>B;
    ll cana=A/K,canb=B/K;
    if(cana==0&&canb==0) cout<<-1<<endl;
    else if(cana==0){
        if(B%K==0) cout<<canb<<endl;
        else cout<<-1<<endl;
    }else if(canb==0){
        if(A%K==0) cout<<cana<<endl;
        else cout<<-1<<endl;
    }else{
        cout<<cana+canb<<endl;
    }
}