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
        x=root(x),y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){return root(x)==root(y);}
    int size(int x){return rank[root(x)];}
    int count(){return num;}
};

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(2,vector<int>(n));
    vector<int> cnt(n,0);
    for (int i=0;i<2;++i){
        for (int j=0;j<n;++j){
            cin >> a[i][j];
            ++cnt[--a[i][j]];
        }
    }

    for (int i=0;i<n;++i){
        if (cnt[i]!=2){
            cout << -1 << '\n';
            return;
        }
    }

    UnionFind UF(n);
    for (int i=0;i<n;++i) UF.merge(a[0][i],a[1][i]);

    vector<int> r(n,0);
    vector<vector<int>> G(n);
    for (int i=0;i<n;++i){
        r[UF.root(i)]=1;
        G[a[0][i]].emplace_back(i);
        G[a[1][i]].emplace_back(i);
    }

    auto other=[&](int v,int i){return (i==G[v][0]?G[v][1]:G[v][0]);};
    auto calc=[&](int r){
        int e=G[r][0];
        vector<int> res;
        for (int _=0;_<2;++_){
            int now=other(r,e);
            vector<int> cnt;
            if (_) cnt.emplace_back(e+1);
            while(now!=e){
                if (a[0][now]==r) cnt.emplace_back(now+1);
                r=a[0][now]+a[1][now]-r,now=other(r,now);
            }
            if (!_||cnt.size()<res.size()) res=cnt;
            swap(a[0][e],a[1][e]);
        }
        return res;
    };

    vector<int> ans;
    for (int i=0;i<n;++i){
        if (r[i]){
            for (int e:calc(i)){
                ans.emplace_back(e);
            }
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}