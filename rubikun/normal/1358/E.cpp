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
    ll M=(N+1)/2;
    vector<ll> A(M),sum(M+1);
    for(int i=0;i<M;i++) cin>>A[i];
    for(int i=1;i<=M;i++){
        sum[i]=sum[i-1];
        sum[i]+=A[i-1];
    }
    ll X;cin>>X;
    
    ll S=sum[M]+X*(N-M);
    
    if(S>0){
        cout<<N<<endl;
    }else{
        if(X>=0){
            cout<<-1<<endl;
        }else{
            for(int i=0;i<N-M;i++){
                sum.push_back(sum.back()+X);
            }
            vector<int> ok;
            for(int i=M;i>=1;i--){
                if(sum[N-i]>0&&sum.back()-sum[i]>0) ok.push_back(N-i);
            }
            
            for(int t:ok){
                bool flag=true;
                for(int i=t;i<=N;i++){
                    if(sum[i]-sum[i-t]<=0){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cout<<t<<endl;
                    return 0;
                }
            }
            cout<<-1<<endl;
        }
    }
    
}