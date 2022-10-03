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
const int INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int sum1=0,sum2=0;
        
        for(int i=0;i<N;i++){
            int space=A[i]-1-sum1-i;
            if(space) sum1++;
        }
        for(int i=N-1;i>=0;i--){
            int space=2*N-A[i]-sum2-(N-1-i);
            if(space) sum2++;
        }
        
        cout<<(N+1-(N-sum1)-(N-sum2))<<"\n";
    }
}