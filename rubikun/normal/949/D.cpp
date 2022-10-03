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
    
    ll N,D,X;cin>>N>>D>>X;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    vector<ll> sum(N+1);
    for(int i=1;i<=N;i++){
        sum[i]=sum[i-1]+A[i-1];
    }
    ll p1=0,ng1=0,p2=0,ng2=0;
    
    for(int i=0;i<(N+1)/2;i++){
        if(sum[min(N,D*(i+1)+i+1)]-p1*X>=X){
            p1++;
        }else{
            ng1++;
        }
    }
    
    for(int i=N-1;i>=(N+1)/2;i--){
        if(sum[N]-sum[max(0LL,-D*(N-i)+i)]-p2*X>=X){
            p2++;
        }else{
            ng2++;
        }
    }
    
    cout<<max(ng1,ng2)<<endl;
}