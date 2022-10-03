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
const int mod=1000000007,MAX=1005,INF=1<<30;

//from : https://ei1333.github.io/luzhiled/snippets/structure/union-find.html

template< typename T >
struct WeightedUnionFind {
    map<int,int> data;
    map<int,T> ws;
    
    WeightedUnionFind() {}
    
    void init(int u){
        if(data.count(u)==0){
            data[u]=-1;
            ws[u]=0;
        }
    }
    
    int find(int k) {
        if(data[k] < 0) return k;
        auto par = find(data[k]);
        ws[k] ^= ws[data[k]];
        return data[k] = par;
    }
    
    T weight(int t) {
        find(t);
        return ws[t];
    }
    
    bool check(int x,int y){
        x=find(x);
        y=find(y);
        
        return (x==y);
    }
    
    bool unite(int x, int y, T w) {
        w ^= weight(x);
        w ^= weight(y);
        x = find(x), y = find(y);
        if(x == y) return false;
        data[x] += data[y];
        data[y] = x;
        ws[y] = w;
        return true;
    }
    
    T diff(int x, int y) {
        return weight(y) ^ weight(x);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    int last=0;
    
    WeightedUnionFind<int> uf;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int l,r,x;cin>>l>>r>>x;
            l^=last;
            r^=last;
            x^=last;
            
            if(l>r) swap(l,r);
            
            r++;
            
            uf.init(l);
            uf.init(r);
            
            uf.unite(l,r,x);
        }else{
            int l,r;cin>>l>>r;
            l^=last;
            r^=last;
            
            if(l>r) swap(l,r);
            
            r++;
            
            uf.init(l);
            uf.init(r);
            
            if(uf.check(l,r)){
                cout<<uf.diff(l,r)<<"\n";
                last=uf.diff(l,r);
            }else{
                cout<<-1<<"\n";
                last=1;
            }
        }
    }
}