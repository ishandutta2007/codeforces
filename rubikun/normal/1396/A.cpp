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
    
    ll N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    if(N==1){
        cout<<1<<" "<<1<<endl;
        cout<<-A[0]<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
    }else{
        cout<<1<<" "<<N-1<<endl;
        for(int i=0;i<N-1;i++){
            cout<<A[i]*(N-1)<<" ";
            A[i]+=(A[i])*(N-1);
        }
        cout<<endl;
        
        cout<<N<<" "<<N<<endl;
        cout<<-A[N-1]<<endl;
        A[N-1]=0;
        
        cout<<1<<" "<<N<<endl;
        for(int i=0;i<N;i++){
            cout<<-A[i]<<" ";
        }
        cout<<endl;
        
    }
    
}