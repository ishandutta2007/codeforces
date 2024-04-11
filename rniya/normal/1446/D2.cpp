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

const int sz=400,MAX_N=200010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n),cnt(n,0);
    int mode=0;
    for (int i=0,Max=0;i<n;++i){
        cin >> a[i]; --a[i];
        if (Max<(++cnt[a[i]])){
            Max=cnt[a[i]];
            mode=a[i];
        }
    }

    int ans=0;
    auto solve1=[&](int num){
        vector<int> ncnt(n,0);
        int res=0;
        for (int l=0,r=0,max_cnt=0;r<n;++r){
            ++ncnt[a[r]];
            if (ncnt[a[r]]==num) ++max_cnt;
            else if (ncnt[a[r]]>num) --max_cnt;
            while (ncnt[a[r]]>num){
                if (ncnt[a[l]]==num) --max_cnt;
                --ncnt[a[l]];
                if (ncnt[a[l]]==num) ++max_cnt;
                ++l;
            }
            if (max_cnt>1) res=max(res,r-l+1);
        }
        return res;
    };
    auto solve2=[&](int v){
        if (v==mode) return 0;
        vector<int> mp(2*MAX_N,n);
        mp[MAX_N]=-1;
        int res=0;
        for (int i=0,diff=MAX_N;i<n;++i){
            if (a[i]==v) ++diff;
            if (a[i]==mode) --diff;
            mp[diff]=min(mp[diff],i);
            res=max(res,i-mp[diff]);
        }
        return res;
    };
    for (int i=1;i<=sz;++i) ans=max(ans,solve1(i));
    for (int i=0;i<n;++i){
        if (cnt[i]>sz){
            ans=max(ans,solve2(i));
        }
    }

    cout << ans << '\n';
}