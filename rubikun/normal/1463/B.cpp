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
        vector<ll> A(N);
        ll sum1=0,sum2=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(i&1) sum2+=A[i];
            else sum1+=A[i];
        }
        
        if(sum1<=sum2){
            for(int i=0;i<N;i++){
                if(i&1) cout<<A[i]<<" ";
                else cout<<1<<" ";
            }
            cout<<"\n";
        }else{
            for(int i=0;i<N;i++){
                if(i&1) cout<<1<<" ";
                else cout<<A[i]<<" ";
            }
            cout<<"\n";
        }
    }
}