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

template<typename T,bool isMin=true>
struct ConvexHullTrick{
    struct Line{
        T a,b;
        Line(T a,T b):a(a),b(b){}
    };
    deque<Line> Lines;
    bool empty() const {return Lines.empty();}
    inline int sgn(T a){return a==0?0:(a<0?-1:1);}
    inline bool check(const Line &a,const Line &b,const Line &c){
        if (b.b==a.b||c.b==b.b) return sgn(b.a-a.a)*sgn(c.b-b.b)>=sgn(c.a-b.a)*sgn(b.b-a.b);
        return (long double)(b.a-a.a)*sgn(c.b-b.b)/(long double)abs(b.b-a.b)>=(long double)(c.a-b.a)*sgn(b.b-a.b)/(long double)abs(c.b-b.b);
    }
    void add(T a,T b){
        if (!isMin) a*=-1,b*=-1;
        Line l(a,b);
        if (empty()){
            Lines.emplace_back(l);
            return;
        }
        if (Lines.front().a<=a){
            if (Lines.front().a==a){
                if (Lines.front().b<=b) return;
                Lines.pop_front();
            }
            while(Lines.size()>=2&&check(l,Lines.front(),Lines[1])) Lines.pop_front();
            Lines.emplace_front(l);
        } else {
            if (Lines.back().a==a){
                if (Lines.back().b<=b) return;
                Lines.pop_back();
            }
            while(Lines.size()>=2&&check(Lines[Lines.size()-2],Lines.back(),l)) Lines.pop_back();
            Lines.emplace_back(l);
        }
    }
    inline T f(const Line &l,const T &x){
        return l.a*x+l.b;
    }
    T query(T x){
        int lb=-1,ub=Lines.size()-1;
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (f(Lines[mid],x)>=f(Lines[mid+1],x)?lb:ub)=mid;
        }
        return (isMin?f(Lines[ub],x):-f(Lines[ub],x));
    }
    T query_monotone_inc(T x){
        while(Lines.size()>=2&&f(Lines.front(),x)>=f(Lines[1],x)) Lines.pop_front();
        return (isMin?f(Lines.front(),x):-f(Lines.front(),x));
    }
    T query_monotone_dec(T x){
        while(Lines.size()>=2&&f(Lines.back(),x)>=f(Lines[Lines.size()-2],x)) Lines.pop_back();
        return (isMin?f(Lines.back(),x):-f(Lines.back(),x));
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<tuple<ll,ll,int>> sr;
    for (int i=0;i<n;++i){
        ll s,r; cin >> s >> r;
        sr.emplace_back(s,r,i);
    }
    sort(ALL(sr));

    struct Line{
        ll s,r; vector<int> idxs;
        Line(ll s,ll r,int id):s(s),r(r){
            idxs.emplace_back(id);
        }
    };
    deque<Line> Lines;

    auto check=[](Line a,Line b,Line c){
        return c.s*a.r*(b.r-c.r)*(a.s-b.s)>a.s*c.r*(a.r-b.r)*(b.s-c.s);
    };
    auto add=[&](int s,int r,int id){
        if (Lines.empty()){
            Lines.emplace_back(s,r,id);
            return;
        }
        Line l(s,r,id);
        if (Lines.back().s==s){
            if (Lines.back().r>r) return;
            else if (Lines.back().r<r) Lines.pop_back();
            else {
                Lines.back().idxs.emplace_back(id);
                return;
            }
        }
        while (Lines.size()>=2&&check(Lines[Lines.size()-2],Lines.back(),l)) Lines.pop_back();
        Lines.emplace_back(l);
    };

    for (int i=0;i<n;++i) add(get<0>(sr[i]),get<1>(sr[i]),get<2>(sr[i]));
    while (Lines.size()>1){
        Line l1=Lines[0],l2=Lines[1];
        if (l1.r<=l2.r) Lines.pop_front();
        else break;
    }
    vector<int> ans;
    for (auto l:Lines){
        for (int id:l.idxs){
            ans.emplace_back(id);
        }
    }
    sort(ALL(ans));
    for (int i=0;i<ans.size();++i) cout << ans[i]+1 << (i+1==ans.size()?'\n':' ');
}