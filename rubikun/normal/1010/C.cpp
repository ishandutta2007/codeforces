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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]%=K;
    }
    
    int now=K;
    
    while(1){
        bool ok=false;
        for(int i=0;i<N;i++){
            int g=gcd(A[i],now);
            if(2<=g&&g<now){
                ok=true;
                for(int j=0;j<N;j++){
                    A[j]=A[j]%g;
                }
                now=g;
                break;
            }
        }
        if(!ok) break;
        if(now==1) break;
    }
    
    set<int> SE;
    for(int i=0;i<N;i++) SE.insert(A[i]);
    
    if(*SE.rbegin()){
        cout<<K<<endl;
        for(int i=0;i<K;i++) cout<<i<<" ";
        cout<<endl;
    }else{
        cout<<K/now<<endl;
        for(int i=0;i<K;i+=now) cout<<i<<" ";
        cout<<endl;
    }
}