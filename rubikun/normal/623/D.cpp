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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<double> P(N);
    vector<double> ng(N);
    for(int i=0;i<N;i++){
        cin>>P[i];P[i]/=100;
        ng[i]=1;
    }
    
    double ans=0;
    double la=0;
    for(int t=0;t<500000;t++){
        if(t<N){
            ng[t]=1.0-P[t];
        }else{
            pair<double,int> ma=mp(la,-1);
            for(int i=0;i<N;i++){
                double x=la;
                x/=(1.0-ng[i]);
                x*=(1.0-ng[i]*(1.0-P[i]));
                chmax(ma,mp(x,i));
            }
            ng[ma.se]*=1.0-P[ma.se];
        }
        double ok=1;
        for(int i=0;i<N;i++){
            ok*=(1.0-ng[i]);
        }
        ans+=(ok-la)*(t+1);
        la=ok;
    }
    
    cout<<setprecision(25)<<ans<<endl;
}