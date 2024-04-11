#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=INT_MAX;
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

template<typename T>
struct BinaryIndexedTree{
    vector<T> dat;
    BinaryIndexedTree(int n):dat(n+1,0){}
    void add(int i,T x){
        if (i==0) return;
        for (;i<=dat.size();i+=(i&-i)) dat[i]+=x;
    }
    T sum(int i){
        T res=0;
        for (;i>0;i-=(i&-i)) res+=dat[i];
        return res;
    }
    T query(int l,int r){ //[l,r)
        return sum(r-1)-sum(l-1);
    }
    int lower_bound(T x){
        if (x<=0) return 0;
        int lb=0,r=1;
        while(r<dat.size()) r<<=1;
        for (;r>0;r>>=1){
            if (lb+r<dat.size()&&dat[lb+r]<x){
                x-=dat[lb+r]; lb+=r;
            }
        }
        return lb+1;
    }
    void add0(int i,T x){add(i+1,x);}
    T sum0(int i){return sum(i+1);}
    T query0(int l,int r){return sum(r)-sum(l);}
};

const int MAX_T=1e4+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<vector<pair<int,int>>> T(4);
    for (int i=0;i<n;++i){
        int t,a,b; cin >> t >> a >> b;
        T[a*2+b].emplace_back(t,i+1);
    }

    vector<vector<int>> sum(4,vector<int>(n+1,0));
    for (int i=0;i<4;++i){
        sort(T[i].begin(),T[i].end());
        for (int j=0;j<T[i].size();++j) sum[i][j+1]+=T[i][j].first;
        for (int j=0;j<n;++j) sum[i][j+1]+=sum[i][j];
    }

    BinaryIndexedTree<int> BIT1(MAX_T),BIT2(MAX_T);
    auto add=[&](int t){
        BIT1.add(t,1);
        BIT2.add(t,t);
    };
    for (auto p:T[0]) add(p.first);
    for (int i=1;i<=2;++i){
        for (int j=k;j<T[i].size();++j){
            add(T[i][j].first);
        }
    }

    auto calc=[&](int x){
        int lb=BIT1.lower_bound(x);
        int res=BIT2.sum(lb);
        res-=(BIT1.sum(lb)-x)*lb;
        return res;
    };

    int ans=INF,both,need;
    for (int i=0;i<=T[3].size();++i){
        need=max(0,k-i);
        if (T[1].size()>=need&&T[2].size()>=need&&m-2*need-i>=0&&m-2*need-i<=BIT1.sum(MAX_T)){
            if (chmin(ans,(k-i>=0?sum[1][k-i]+sum[2][k-i]:0)+sum[3][i]+calc(m-2*need-i))){
                both=i;
            }
        }
        if (i==T[3].size()) continue;
        if (0<=k-1-i&&k-1-i<T[1].size()) add(T[1][k-1-i].first);
        if (0<=k-1-i&&k-1-i<T[2].size()) add(T[2][k-1-i].first);
    }

    if (ans==INF){cout << -1 << '\n'; return 0;}

    vector<int> v;
    priority_queue<pair<int,int>> pq;
    for (int i=0;i<both;++i) v.emplace_back(T[3][i].second);
    for (int i=0;i<=2;++i){
        for (int j=0;j<T[i].size();++j){
            if (i>0&&j<k-both) v.emplace_back(T[i][j].second);
            else pq.emplace(-T[i][j].first,T[i][j].second);
        }
    }

    need=max(0,k-both);
    for (int i=2*need+both;i<m;++i){
        auto p=pq.top(); pq.pop();
        v.emplace_back(p.second);
    }

    cout << ans << '\n';
    cout << v << '\n';
}