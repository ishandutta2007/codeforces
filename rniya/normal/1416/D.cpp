#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
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
    os << '(' << p.first << ',' << p.second << ')';
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
    vector<int> par,rank;
    UnionFind(int n):num(n),par(n),rank(n,1){
        iota(par.begin(),par.end(),0);
    }
    int root(int x){
        return (par[x]==x?x:par[x]=root(par[x]));
    }
    bool merge(int x, int y){
        x=root(x); y=root(y);
        if (x==y) return false;
        // if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){return root(x)==root(y);}
    int size(int x){return rank[root(x)];}
    int count(){return num;}
};

template<typename Monoid>
struct SegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_,F f,Monoid id):f(f),id(id){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        dat.assign(n<<1,id);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    void update(int k,Monoid x){
        dat[k+=n]=x;
        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);
    }
    Monoid query(int a,int b){
        if (a>=b) return id;
        Monoid vl=id,vr=id;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,dat[l++]);
            if (r&1) vr=f(dat[--r],vr);
        }
        return f(vl,vr);
    }
    template<typename C>
    int find_subtree(int k,const C &check,Monoid &M,bool type){
        while(k<n){
            Monoid nxt=type?f(dat[k<<1|type],M):f(M,dat[k<<1|type]);
            if (check(nxt)) k=k<<1|type;
            else M=nxt,k=k<<1|(type^1);
        }
        return k-n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template<typename C>
    int find_first(int a,const C &check){
        Monoid L=id;
        if (a<=0){
            if (check(f(L,dat[1]))) return find_subtree(1,check,L,false);
            return -1;
        }
        int b=n;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1){
                Monoid nxt=f(L,dat[l]);
                if (check(nxt)) return find_subtree(l,check,L,false);
                L=nxt; ++l;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template<typename C>
    int find_last(int b,const C &check){
        Monoid R=id;
        if (b>=n){
            if (check(f(dat[1],R))) return find_subtree(1,check,R,true);
            return -1;
        }
        int a=n;
        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){
            if (r&1){
                Monoid nxt=f(dat[--r],R);
                if (check(nxt)) return find_subtree(r,check,R,true);
                R=nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i){return dat[i+n];}
};

typedef pair<int,int> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,q; cin >> n >> m >> q;
    vector<int> p(n),a(m),b(m),t(q),x(q),used(m,0);
    for (int i=0;i<n;++i) cin >> p[i];
    for (int i=0;i<m;++i) cin >> a[i] >> b[i],--a[i],--b[i];
    for (int i=0;i<q;++i){
        cin >> t[i] >> x[i],--x[i];
        if (t[i]==2) used[x[i]]=1;
    }
    for (int i=0;i<m;++i){
        if (!used[i]){
            t.emplace_back(2);
            x.emplace_back(i);
        }
    }

    vector<vector<int>> G(n+m);
    UnionFind UF(n+m);
    vector<int> r(q);
    auto rev1=[&](int v){return UF.root(v);};
    auto rev2=[&](int e){
        int A=UF.root(a[e]),B=UF.root(b[e]);
        if (A==B) return;
        G[n+e].emplace_back(A); G[n+e].emplace_back(B);
        UF.merge(n+e,a[e]); UF.merge(n+e,b[e]);
    };
    for (int i=t.size()-1;i>=0;--i){
        if (t[i]==1) r[i]=rev1(x[i]);
        else rev2(x[i]);
    }

    int time=0;
    vector<int> ls(n+m),rs(n+m);
    auto dfs=[&](auto self,int v)->void{
        ls[v]=time++;
        for (int u:G[v]) self(self,u);
        rs[v]=time;
    };
    for (int i=0;i<n+m;++i){
        if (UF.root(i)==i) dfs(dfs,i);
    }
    SegmentTree<P> seg(n+m,[](P a,P b){return b.first>a.first?b:a;},{0,0});
    for (int i=0;i<n;++i) seg.update(ls[i],{p[i],ls[i]});
    for (int i=n;i<n+m;++i) seg.update(ls[i],{0,ls[i]});

    auto query=[&](int R){
        auto p=seg.query(ls[R],rs[R]);
        if (p.first!=0) seg.update(p.second,{0,p.second});
        return p.first;
    };
    for (int i=0;i<q;++i){
        if (t[i]==1) cout << query(r[i]) << '\n';
    }
}