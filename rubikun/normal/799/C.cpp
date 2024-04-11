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
const int mod=1000000007,MAX=200005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,C,D;cin>>N>>C>>D;
    vector<pair<int,int>> A,B;
    A.push_back(mp(-INF,-INF));
    B.push_back(mp(-INF,-INF));
    A.push_back(mp(INF,-INF));
    B.push_back(mp(INF,-INF));
    
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        char c;cin>>c;
        if(c=='C'){
            A.push_back(mp(b,a));
        }else{
            B.push_back(mp(b,a));
        }
    }
    
    sort(all(A));
    sort(all(B));
    
    vector<pair<int,int>> AA=A,BB=B;
    
    for(int i=1;i<si(A);i++){
        chmax(A[i].se,A[i-1].se);
    }
    for(int i=1;i<si(B);i++){
        chmax(B[i].se,B[i-1].se);
    }
    
    int ans=0;
    
    for(int i=0;i<si(AA);i++){
        int d=lower_bound(all(A),mp(C-AA[i].fi,INF))-A.begin()-1;
        chmin(d,i-1);
        if(d>=0) chmax(ans,AA[i].se+A[d].se);
    }
    
    for(int i=0;i<si(BB);i++){
        int d=lower_bound(all(B),mp(D-BB[i].fi,INF))-B.begin()-1;
        chmin(d,i-1);
        if(d>=0) chmax(ans,BB[i].se+B[d].se);
    }
    
    int da=lower_bound(all(A),mp(C,INF))-A.begin()-1;
    int db=lower_bound(all(B),mp(D,INF))-B.begin()-1;
    
    chmax(ans,A[da].se+B[db].se);
    
    cout<<ans<<endl;
}