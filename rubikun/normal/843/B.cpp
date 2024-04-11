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
const int mod=1000000007,MAX=300005,INF=1<<30;

pair<int,int> ask(int id){
    cout<<"? "<<id+1<<endl;
    int a,b;cin>>a>>b;
    return mp(a,b);
}

void output(int x){
    cout<<"! "<<x<<endl;
    exit(0);
}

int main() {
    
    /*
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
     */
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int N,S,X;cin>>N>>S>>X;
    S--;
    if(N<=1999){
        vector<int> res(N);
        for(int i=0;i<N;i++){
            auto x=ask(i);
            res[i]=x.fi;
        }
        int ans=INF;
        for(int i=0;i<N;i++){
            if(res[i]>=X) chmin(ans,res[i]);
        }
        if(ans==INF) ans=-1;
        output(ans);
    }else{
        set<int> SE;
        SE.insert(S);
        while(1){
            int x=rng()%N;
            SE.insert(x);
            if(si(SE)==999) break;
        }
        vector<pair<int,int>> res;
        for(int a:SE){
            auto x=ask(a);
            res.push_back(mp(x.fi,a));
        }
        sort(all(res));
        if(res[0].fi>=X){
            output(res[0].fi);
        }
        
        auto it=lower_bound(all(res),mp(X,-1));
        it--;
        int now=(*it).se;
        while(1){
            auto x=ask(now);
            if(x.fi>=X){
                output(x.fi);
            }else{
                if(x.se==-1) output(-1);
                else now=x.se-1;
            }
        }
    }
    
    
}