#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
// const long long MOD=998244353;
#define LOCAL
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(),(x).end()
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
template<typename T,typename U,typename V>
ostream&operator<<(ostream &os,const tuple<T,U,V> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template<typename T,typename U,typename V,typename W>
ostream&operator<<(ostream &os,const tuple<T,U,V,W> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const unordered_map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const multiset<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const unordered_set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const deque<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
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

const int MAX_B=30;

int msb(int x){
    for (int i=MAX_B-1;i>=0;--i){
        if (x&1<<i){
            return i;
        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); cin >> a;

    vector<int> cnt(MAX_B,0);
    for (int i=0;i<n;++i) ++cnt[msb(a[i])];
    for (int i=0;i<MAX_B;++i){
        if (cnt[i]>2){
            cout << 1 << '\n';
            return 0;
        }
    }

    auto inc=[](vector<int> v){
        for (int i=0;i+1<v.size();++i){
            if (v[i+1]<v[i]) return true;
        }
        return false;
    };
    auto check1=[&](int l,int r){
        vector<int> b;
        for (int i=0;i<l;++i) b.emplace_back(a[i]);
        int XOR=0;
        for (int i=l;i<r;++i) XOR^=a[i];
        b.emplace_back(XOR);
        for (int i=r;i<n;++i) b.emplace_back(a[i]);
        return (inc(b)?n-b.size():INF);
    };

    auto check2=[&](int l1,int r1,int l2,int r2){
        vector<int> b;
        for (int i=0;i<l1;++i) b.emplace_back(a[i]);
        int XOR1=0;
        for (int i=l1;i<r1;++i) XOR1^=a[i];
        b.emplace_back(XOR1);
        for (int i=r1;i<l2;++i) b.emplace_back(a[i]);
        int XOR2=0;
        for (int i=l2;i<r2;++i) XOR2^=a[i];
        b.emplace_back(XOR2);
        for (int i=r2;i<n;++i) b.emplace_back(a[i]);
        return (inc(b)?n-b.size():INF);
    };

    int ans=INF;
    for (int i=0;i<n;++i){
        for (int j=i+2;j<=n;++j){
            chmin(ans,check1(i,j));
        }
    }

    for (int i=0;i<n;++i){
        for (int j=i+2;j<=n;++j){
            for (int k=j;k<n;++k){
                for (int l=k+2;l<=n;++l){
                    chmin(ans,check2(i,j,k,l));
                }
            }
        }
    }

    cout << (ans==INF?-1:ans) << '\n';
}