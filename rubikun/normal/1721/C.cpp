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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        
        for(int i=0;i<N;i++){
            cout<<*(lower_bound(all(B),A[i]))-A[i]<<" ";
        }
        cout<<"\n";
        vector<int> ng;
        for(int i=1;i<N;i++){
            if(A[i]>B[i-1]) ng.push_back(i);
        }
        
        for(int i=0;i<N;i++){
            auto it=lower_bound(all(ng),i+1);
            if(it==ng.end()){
                cout<<B.back()-A[i]<<" ";
            }else{
                cout<<B[(*it)-1]-A[i]<<" ";
            }
        }
        cout<<"\n";
    }
}