#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

const int MAX_N=210;

int n;
int K[MAX_N];
vector<set<int>> p(MAX_N);

void solve(){
    vector<int> cnt(n,0);
    for (int i=0;i<n-1;++i){
        for (int x:p[i]) ++cnt[x];
    }
    vector<int> once;
    for (int i=0;i<n;++i) if (cnt[i]==1){
        once.emplace_back(i);
    }
    for (int _=0;_<once.size();++_){
        int x=once[_];
        for (int f=0;f<n;++f){
            if (f==x) continue;
            if (once.size()>1&&f!=once[_^1]) continue;
            vector<int> ans(n,-1),used(n-1,0),cnt1(n);
            for (int i=0;i<n;++i) cnt1[i]=cnt[i];
            ans[n-1]=x;
            int ok=1;
            for (int i=n-2;i>=1;--i){
                int nxt=-1;
                for (int j=0;j<n-1;++j){
                    if (used[j]) continue;
                    if (p[j].count(ans[i+1])) nxt=j;
                }
                if (nxt<0){ok=0; break;}
                used[nxt]=i+1;
                int zero=0;
                for (int a:p[nxt]){
                    --cnt1[a];
                    if (i>1&&a!=f&&cnt1[a]==1) ans[i]=a,++zero;
                }
                if (i>1&&(ans[i]<0||zero>1)){ok=0;break;}
            }
            vector<int> still;
            for (int i=0;i<n;++i) if (cnt1[i]!=0){
                if (cnt1[i]>1) ok=0;
                still.emplace_back(i);
            }
            if (!ok||still.size()!=2) continue;
            if (cnt[still[0]]>cnt[still[1]]) swap(still[0],still[1]);
            if (f!=still[0]){
                if (cnt[still[0]]==cnt[still[1]]) swap(still[0],still[1]);
                if (f!=still[0]) continue;
            }
            ans[0]=still[0],ans[1]=still[1];
            for (int j=0;j<n-1;++j){
                int id=used[j];
                if (!id) continue;
                for (int k=id-K[j]+1;k<=id;++k){
                    if (!p[j].count(ans[k])) ok=0;
                }
            }
            if (!ok) continue;
            for (int i=0;i<n;++i) cout << ans[i]+1 << (i+1==n?'\n':' ');
            return;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n;
        for (int i=0;i<n-1;++i){
            cin >> K[i]; p[i].clear();
            for (int j=0;j<K[i];++j){
                int P; cin >> P;
                p[i].emplace(--P);
            }
        }
        solve();
    }
}