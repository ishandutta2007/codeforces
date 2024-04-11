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

const int MAX_A=510;

void solve(){
    int n; cin >> n;
    vector<int> a(n); cin >> a;

    bool same=false;
    int inv=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<i;++j){
            inv+=(a[j]>a[i]);
            if (a[i]==a[j]) same=true;
        }
    }

    if (!same&&(inv&1)){cout << -1 << '\n'; return;}

    vector<pair<int,int>> A;
    for (int i=0;i<n;++i) A.emplace_back(a[i],i);
    sort(A.begin(),A.end());
    if (inv&1){
        bool ok=false;
        for (int i=0;i<n;++i){
            for (int j=0;j<i;++j){
                if (ok) break;
                if (A[i].first==A[j].first){
                    swap(A[i].second,A[j].second);
                    ok=true;
                }
            }
        }
    }

    for (int i=0;i<n;++i) a[A[i].second]=i;

    vector<int> ans;
    auto shift=[&](int i){
        ans.emplace_back(i+1);
        swap(a[i+2],a[i+1]);
        swap(a[i+1],a[i]);
    };
    for (int i=0;i<n;++i){
        while(a[i]!=i){
            int nxt;
            for (int j=0;j<n;++j){
                if (a[j]==i) nxt=j;
            }
            shift((!(abs(nxt-i)&1)||nxt==n-1)?nxt-2:nxt-1);
        }
    }

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