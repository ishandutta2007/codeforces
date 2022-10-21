#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

struct UnionFind{
    int num;
    vector<int> par,rank,ON;
    UnionFind(int n,vector<int> color):num(n),par(n),rank(n,1),ON(n){
        iota(par.begin(),par.end(),0);
        for (int i=0;i<n;++i) ON[i]=color[i];
    }
    int root(int x){
        return (par[x]==x?x:par[x]=root(par[x]));
    }
    bool merge(int x, int y){
        x=root(x),y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        ON[x]+=ON[y];
        --num;
        return true;
    }
    bool same(int x, int y){return root(x)==root(y);}
    pair<int,int> size(int x){return {ON[root(x)],rank[root(x)]};}
    int get(int x){
        auto p=size(x);
        return (same(x,(int)par.size()-1)?p.first:min(p.first,p.second-p.first));
    }
    int count(){return num;}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; string S; cin >> n >> k >> S;
    vector<int> T(n);
    for (int i=0;i<n;++i) T[i]=(S[i]-'0')^1;
    vector<vector<int>> sub(n);
    for (int i=0;i<k;++i){
        int c; cin >> c;
        for (;c--;){
            int x; cin >> x;
            sub[--x].emplace_back(i);
        }
    }
    vector<vector<pair<int,int>>> G(k+1);
    for (int i=0;i<n;++i){
        if (sub[i].empty()) continue;
        if (sub[i].size()==1){
            int u=sub[i][0];
            G[u].emplace_back(k,T[i]);
            G[k].emplace_back(u,T[i]);
        } else {
            int u=sub[i][0],v=sub[i][1];
            G[u].emplace_back(v,T[i]);
            G[v].emplace_back(u,T[i]);
        }
    }
    vector<int> color(k+1,-1);
    auto dfs=[&](auto self,int v,int c)->void{
        color[v]=c;
        for (auto e:G[v]){
            int u=e.first;
            if (~color[u]) continue;
            self(self,u,c^e.second);
        }
    };
    for (int i=k;i>=0;--i){
        if (color[i]<0){
            dfs(dfs,i,0);
        }
    }
    UnionFind UF(k+1,color);
    int ans=0;
    auto f=[&](int i){
        if (sub[i].empty()) return;
        if (sub[i].size()==1){
            int u=sub[i][0];
            if (UF.same(u,k)) return;
            ans-=UF.get(u)+UF.get(k);
            UF.merge(u,k);
            ans+=UF.get(u);
        } else {
            int u=sub[i][0],v=sub[i][1];
            if (UF.same(u,v)) return;
            ans-=UF.get(u)+UF.get(v);
            UF.merge(u,v);
            ans+=UF.get(u);
        }
    };
    for (int i=0;i<n;++i){
        f(i);
        cout << ans << '\n';
    }
}