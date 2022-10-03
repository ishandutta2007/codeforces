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
const ll INF=1LL<<61;
bool ok=false;
vector<int> A;

void check(int now,int ng,int sum){
    if(now==si(A)){
        if(sum==A[ng]) ok=true;
        return;
    }
    if(now==ng) check(now+1,ng,sum);
    else{
        check(now+1,ng,sum+A[now]);
        check(now+1,ng,sum);
        check(now+1,ng,sum-A[now]);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        A.clear();
        A.resize(N);
        for(int i=0;i<N;i++) cin>>A[i];
        ok=false;
        
        for(int t=0;t<N;t++){
            check(0,t,0);
        }
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}