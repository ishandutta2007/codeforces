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
const int mod=998244353,MAX=300005,INF=1<<30;

struct edge{
    int a;
    int b;
    int c;
    bool use;
    int id;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<edge> E(M);
    for(int i=0;i<M;i++){
        int x,y;cin>>x>>y;
        E[i]={-1,-1,x,(bool)y,i};
    }
    sort(all(E),[](auto a,auto b){
        if(a.c==b.c) return a.use>b.use;
        return a.c<b.c;
    });
    
    set<pair<int,int>> can;
    int sz=0;
    for(auto &e:E){
        if(e.use){
            e.a=sz;
            e.b=sz+1;
            for(int i=0;i<sz;i++){
                if(si(can)<=M) can.insert(mp(i,sz+1));
                else break;
            }
            sz++;
        }else{
            if(si(can)){
                auto it=can.begin();
                e.a=(*it).fi;
                e.b=(*it).se;
                can.erase(it);
            }else{
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    
    sort(all(E),[](auto a,auto b){
        return a.id<b.id;
    });
    
    for(int i=0;i<M;i++) cout<<E[i].a+1<<" "<<E[i].b+1<<"\n";
}