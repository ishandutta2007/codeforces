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
const int mod=1000000007,MAX=4005,D=100;
const int INF=1<<30;
int MA[2205][205][105][2];
bool seen[2205][205][105][2];
int N;
int A[MAX],rui[MAX];

int solve(int l,int r,int k,int turn){
    if(seen[l][r-l+D][k][turn]) return MA[l][r-l+D][k][turn];
    if(l+r+k>N) return 0;
    
    seen[l][r-l+D][k][turn]=1;
    
    if(l+r+k==N){
        if(turn==0) return MA[l][r-l+D][k][turn]=rui[N-r]-rui[l];
        else return MA[l][r-l+D][k][turn]=-(rui[N-r]-rui[l]);
    }
    
    if(turn==0){
        int res=-INF;
        chmax(res,solve(l+k,r,k,turn^1)+rui[l+k]-rui[l]);
        chmax(res,solve(l+k+1,r,k+1,turn^1)+rui[l+k+1]-rui[l]);
        
        return MA[l][r-l+D][k][turn]=res;
    }else{
        int res=INF;
        chmin(res,solve(l,r+k,k,turn^1)-(rui[N-r]-rui[N-(r+k)]));
        chmin(res,solve(l,r+k+1,k+1,turn^1)-(rui[N-r]-rui[N-(r+k+1)]));
        
        return MA[l][r-l+D][k][turn]=res;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i+1];
        rui[i+1]=rui[i]+A[i+1];
    }
    cout<<solve(0,0,1,0)<<endl;
}