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
const int mod=998244353,MAX=100005,INF=1<<30;

vector<int> A={0,1,0,1,2},B={0,1,2,0,1};

int solve(int x){
    if(x<=4){
        return A[x];
    }else if(x&1){
        return 0;
    }else{
        if(solve(x/2)==1) return 2;
        else return 1;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    int X=0;
    
    for(int i=0;i<N;i++){
        int x;cin>>x;
        if(K&1){
            X^=solve(x);
        }else{
            if(x<=4) X^=B[x];
            else{
                if(x&1) X^=0;
                else X^=1;
            }
        }
    }
    
    if(X) cout<<"Kevin\n";
    else cout<<"Nicky\n";
}