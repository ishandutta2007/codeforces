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
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    map<pair<int,int>,int> MA;
    int N;cin>>N;
    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i];P[i]--;
    }
    ll ans=0;
    for(int s=0;s<N;s++){
        vector<int> A,B;
        A.push_back(-INF);B.push_back(INF);
        int la=N-1;
        int upd=N-1;
        auto update=[&](int t){
            if(A.back()<P[t]){
                if(B.back()>P[t]){
                    if(t==N-1||P[t]<P[t+1]) A.push_back(P[t]);
                    else B.push_back(P[t]);
                }else{
                    A.push_back(P[t]);
                }
            }else{
                if(B.back()>P[t]){
                    B.push_back(P[t]);
                }else{
                    la=t-1;
                    upd=t-1;
                    return false;
                }
            }
            return true;
        };
        for(int t=s;t<N;t++){
            if(!update(t)) break;
            if(MA.count(mp(A.back(),B.back()))){
                la=MA[mp(A.back(),B.back())];
                upd=t-1;
                break;
            }
        }
        while(si(A)>1) A.pop_back();
        while(si(B)>1) B.pop_back();
        for(int t=s;t<=upd;t++){
            update(t);
            MA[mp(A.back(),B.back())]=la;
        }
        ans+=la-s+1;
    }
    
    cout<<ans<<endl;
}