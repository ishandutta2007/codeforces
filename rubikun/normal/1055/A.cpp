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
const int mod=1000000007,MAX=2005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,S;cin>>N>>S;
    S--;
    
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    
    bool ok=false;
    
    for(int i=1;i<N;i++){
        if(A[i]){
            if(i==S) ok=true;
            else{
                if(B[i]&&S<i&&B[S]) ok=true;
            }
        }
    }
    
    if(!A[0]) ok=false;
    
    if(ok) cout<<"Yes\n";
    else cout<<"No"<<endl;
}