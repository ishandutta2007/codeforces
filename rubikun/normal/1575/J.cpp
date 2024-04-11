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
const ll INF=1LL<<61;

struct UF{
    int n;
    vector<int> par,size,ma;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        ma.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
            ma[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            chmax(ma[root(a)],ma[root(b)]);
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W,Q;cin>>H>>W>>Q;
    vector<vector<int>> S(H,vector<int>(W));
    vector<UF> T(W);
    for(int j=0;j<W;j++) T[j].init(H+1);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    while(Q--){
        int nowh=0,noww;cin>>noww;noww--;
        while(1){
            nowh=T[noww].ma[T[noww].root(nowh)];
            if(nowh==H) break;
            if(S[nowh][noww]==2){
                T[noww].unite(nowh,nowh+1);
                nowh++;
            }else if(S[nowh][noww]==1){
                T[noww].unite(nowh,nowh+1);
                S[nowh][noww]=2;
                noww++;
            }else{
                T[noww].unite(nowh,nowh+1);
                S[nowh][noww]=2;
                noww--;
            }
        }
        
        cout<<noww+1<<" ";
    }
    cout<<endl;
}