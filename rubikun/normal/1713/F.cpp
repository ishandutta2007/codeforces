//https://atcoder.jp/contests/arc137/submissions/30240045

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

template<typename T>
vector<T> fzt(vector<T> A,bool wh){
    int n=si(A);
    vector<T> res=A;
    
    for(int i=1;i<n;i*=2){
        for(int j=0;j<n;j++){
            if((j&i)==0){
                if(wh) res[j|i]^=res[j];
                else res[j]^=res[j|i];
            }
        }
    }
    
    return res;
}//wh==0 jx wh==1 xj x

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    int K=1;
    while(K<N) K*=2;
    
    vector<ll> A(K);
    for(int i=0;i<N;i++) cin>>A[K-1-i];
    
    vector<ll> B=fzt(A,0);
    
    for(int i=0;i<K-N;i++) B[i]=0;
    
    B=fzt(B,0);
    
    vector<ll> ans=fzt(B,1);
    
    for(int i=0;i<N;i++){
        cout<<ans[N-1-i]<<" ";
    }
    cout<<"\n";
}