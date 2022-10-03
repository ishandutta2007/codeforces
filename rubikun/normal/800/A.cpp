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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<60;

#define double long double

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,P;cin>>N>>P;
    vector<ll> A(N),B(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
        sum+=A[i];
    }
    if(sum<=P){
        cout<<-1<<"\n";
    }else{
        double left=0,right=1e15;
        for(int q=0;q<100;q++){
            double mid=(left+right)/2;
            double need=0;
            for(int i=0;i<N;i++){
                need+=max(0.0l,mid*A[i]-B[i]);
            }
            if(need<=mid*P) left=mid;
            else right=mid;
        }
        cout<<fixed<<setprecision(25)<<left<<"\n";
    }
}