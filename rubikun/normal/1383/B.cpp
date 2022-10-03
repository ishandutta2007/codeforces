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
const int mod=1000000007,MAX=105,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        int X=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            X^=A[i];
        }
        
        if(X==0){
            cout<<"DRAW\n";
            continue;
        }
        
        for(int j=30;j>=0;j--){
            int cnt=0;
            for(int i=0;i<N;i++){
                if(A[i]&(1<<j)) cnt++;
            }
            if(!(cnt&1)) continue;
            
            if(cnt%4==1) cout<<"WIN\n";
            else{
                if(!(N&1)) cout<<"WIN\n";
                else cout<<"LOSE\n";
            }
            break;
        }
    }
    
}