#include <bits/stdc++.h>
using namespace std;
// #define LOCAL
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

using u128=__int128_t;
using T=tuple<u128,u128,int>;
const int MAX_K=100010;
vector<pair<int,int>> v[MAX_K][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k,n,m; cin >> k >> n >> m;
    vector<int> a(k); cin >> a;
    vector<int> Max(k,0),id(k,-1),type(n);
    for (int j=0;j<n;++j){
        int t,i,b; cin >> t >> i >> b; --i;
        type[j]=t-1;
        if (t==1){
            if (chmax(Max[i],b)){
                id[i]=j;
            }
        } else v[i][t-2].emplace_back(b,j);
    }

    auto f=[](pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    };
    auto g=[](T a,T b){
        return get<0>(a)*get<1>(b)<get<1>(a)*get<0>(b);
    };
    priority_queue<T,vector<T>,decltype(g)> pq(g);
    for (int i=0;i<k;++i){
        if (~id[i]&&Max[i]>a[i]) v[i][0].emplace_back(Max[i]-a[i],id[i]);
        sort(v[i][0].begin(),v[i][0].end());
        reverse(v[i][0].begin(),v[i][0].end());
        ll cur=a[i];
        for (auto p:v[i][0]){
            pq.emplace(cur+p.first,cur,p.second);
            cur+=p.first;
        }
        for (auto p:v[i][1]){
            pq.emplace(p.first,1,p.second);
        }
    }

    vector<vector<int>> ans(3);
    for (int _=0;_<m&&!pq.empty();++_){
        auto t=pq.top(); pq.pop();
        int v=get<2>(t);
        ans[type[v]].emplace_back(v);
    }
    vector<int> fans;
    for (int i=0;i<3;++i){
        for (int x:ans[i]){
            fans.emplace_back(x+1);
        }
    }

    cout << fans.size() << '\n';
    cout << fans << '\n';
}