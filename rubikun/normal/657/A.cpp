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
    
    int N,D,H;cin>>N>>D>>H;
    if(H*2<D){
        cout<<-1<<"\n";
    }else if(D==1){
        if(N==2){
            cout<<1<<" "<<2<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }else if(H==D){
        for(int i=1;i<=H;i++){
            cout<<i<<" "<<i+1<<"\n";
        }
        for(int i=H+2;i<=N;i++){
            cout<<2<<" "<<i<<"\n";
        }
    }else{
        for(int i=1;i<=D-H;i++){
            cout<<i<<" "<<i+1<<"\n";
        }
        for(int i=1;i<=H;i++){
            if(i==1) cout<<1<<" ";
            else cout<<i+D-H<<" ";
            cout<<i+D-H+1<<"\n";
        }
        for(int i=D+2;i<=N;i++){
            cout<<1<<" "<<i<<"\n";
        }
        //cout<<"\n";
    }
}