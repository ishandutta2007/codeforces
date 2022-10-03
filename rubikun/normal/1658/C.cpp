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
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        int cn=0,po=-1;
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(A[i]==1){
                cn++;
                po=i;
            }
        }
        if(cn!=1){
            cout<<"NO\n";
        }else{
            for(int i=0;i<N;i++) A.push_back(A[i]);
            bool f=true;
            for(int i=po;i+1<po+N;i++){
                if(A[i]+1<A[i+1]) f=false;
            }
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}