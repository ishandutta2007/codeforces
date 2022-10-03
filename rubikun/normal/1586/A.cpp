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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum+=A[i];
        }
        bool f=false;
        for(int j=2;j<sum;j++){
            if(sum%j==0) f=true;
        }
        if(f){
            cout<<N<<"\n";
            for(int i=1;i<=N;i++) cout<<i<<" ";
            cout<<"\n";
        }else{
            for(int i=0;i<N;i++){
                if(A[i]&1){
                    cout<<N-1<<"\n";
                    for(int j=0;j<N;j++){
                        if(i==j) continue;
                        cout<<j+1<<" ";
                    }
                    cout<<"\n";
                    break;
                }
            }
        }
    }
}