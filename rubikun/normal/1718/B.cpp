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

ll fib[105],fibsum[105];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    fib[0]=0;
    fibsum[0]=0;
    fib[1]=fib[2]=1;
    fibsum[1]=1;
    fibsum[2]=2;
    for(int i=3;i<=80;i++){
        fib[i]=fib[i-1]+fib[i-2];
        fibsum[i]=fibsum[i-1]+fib[i];
    }
    
    map<ll,ll> MA;
    for(int i=0;i<=80;i++) MA[fibsum[i]]=i;
    
    //cout<<fibsum[80]<<endl;
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        priority_queue<pair<ll,int>> PQ;
        ll sum=0;
        for(int i=0;i<N;i++){
            ll x;cin>>x;
            sum+=x;
            PQ.push(mp(x,i));
        }
        if(!MA.count(sum)){
            cout<<"NO\n";
        }else{
            int t=MA[sum];
            int la=-1;
            bool ok=true;
            for(int i=t;i>=1;i--){
                auto [x,id]=PQ.top();PQ.pop();
                if(la==id){
                    if(PQ.empty()){
                        ok=false;
                        break;
                    }
                    auto [y,idid]=PQ.top();PQ.pop();
                    if(y<fib[i]){
                        ok=false;
                        break;
                    }
                    if(y-fib[i]){
                        PQ.push(mp(y-fib[i],idid));
                    }
                    PQ.push(mp(x,id));
                    la=idid;
                }else{
                    if(x<fib[i]){
                        ok=false;
                        break;
                    }
                    if(x-fib[i]) PQ.push(mp(x-fib[i],id));
                    la=id;
                }
            }
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}