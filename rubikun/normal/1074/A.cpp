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
    
    int N,M;cin>>N>>M;
    int ans=INF;
    vector<int> A(N),B;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    A.push_back(1000000000);
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        if(a==1) B.push_back(b);
    }
    
    sort(all(A));
    sort(all(B));
    
    for(int i=0;i<=N;i++){
        int cnt=i;
        
        int x=si(B)-(lower_bound(all(B),A[i])-B.begin());
        chmin(ans,cnt+x);
    }
    
    cout<<ans<<endl;
    
    
}