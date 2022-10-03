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
int N;
vector<int> A;

int solve(int l,int r,int b){
    if(l+1==r) return 1;
    
    if((A[l]&(1<<b))==(A[r-1]&(1<<b))) return solve(l,r,b-1);
    
    int m=lower_bound(all(A),((A[l]>>b)+1)<<b)-A.begin();
    return max(solve(l,m,b-1),solve(m,r,b-1))+1;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    A.resize(N);
    
    for(int i=0;i<N;i++) cin>>A[i];
    
    sort(all(A));
    
    cout<<N-solve(0,N,30)<<endl;
    
}