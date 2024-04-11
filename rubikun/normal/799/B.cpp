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
const int mod=1000000007,MAX=200005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),B(N),C(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    for(int i=0;i<N;i++) cin>>C[i];
    vector<set<ll>> SE(3);
    for(int i=0;i<N;i++){
        int p=A[i],a=B[i]-1,b=C[i]-1;
        SE[a].insert(p);
        SE[b].insert(p);
    }
    
    int M;cin>>M;
    for(int i=0;i<M;i++){
        int c;cin>>c;
        c--;
        if(SE[c].empty()){
            cout<<-1<<" ";
        }else{
            ll x=*SE[c].begin();
            for(int j=0;j<3;j++){
                if(SE[j].count(x)) SE[j].erase(x);
            }
            cout<<x<<" ";
        }
    }
    
    cout<<endl;
}