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
const int mod=998244353,MAX=100005,INF=1<<30;
int rk[20][1<<18];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    for(int i=0;i<(1<<N);i++){
        rk[0][i]=(S[i]-'a');
    }
    for(int t=1;t<=N;t++){
        vector<pair<pair<int,int>,int>> S((1<<N));
        for(int i=0;i<(1<<N);i++){
            S[i]=mp(mp(rk[t-1][i],rk[t-1][i^(1<<(t-1))]),i);
        }
        sort(all(S));
        for(int i=0;i<(1<<N);i++){
            if(i==0) rk[t][S[i].se]=0;
            else{
                if(S[i-1].fi==S[i].fi) rk[t][S[i].se]=rk[t][S[i-1].se];
                else rk[t][S[i].se]=rk[t][S[i-1].se]+1;
            }
        }
    }
    
    pair<int,int> mi=mp(INF,INF);
    for(int i=0;i<(1<<N);i++) chmin(mi,mp(rk[N][i],i));
    int X=mi.se;
    for(int i=0;i<(1<<N);i++){
        cout<<S[i^X];
    }
    cout<<endl;
}