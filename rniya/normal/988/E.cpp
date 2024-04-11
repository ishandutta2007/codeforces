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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int n=S.size();
    if (n==1){cout << -1 << '\n'; return 0;}
    reverse(S.begin(),S.end());
    vector<vector<int>> pos(10);
    for (int i=0;i<n;++i) pos[S[i]-'0'].emplace_back(i);
    vector<vector<int>> v={{0,0},{5,2},{0,5},{5,7}};
    int ans=INF;
    for (int i=0;i<4;++i){
        int cnt=0;
        string T=S;
        if (!i){
            if (pos[0].size()<2) continue;
            for (int j=pos[0][0];j>0;--j,++cnt) swap(T[j],T[j-1]);
            for (int j=pos[0][1];j>1;--j,++cnt) swap(T[j],T[j-1]);
        } else {
            if (pos[v[i][0]].size()<1||pos[v[i][1]].size()<1) continue;
            int pre=pos[v[i][0]][0],suf=pos[v[i][1]][0];
            if (pre<suf){
                for (int j=pre;j>0;--j,++cnt) swap(T[j],T[j-1]);
                for (int j=suf;j>1;--j,++cnt) swap(T[j],T[j-1]);
            } else {
                for (int j=pre;j>0;--j,++cnt) swap(T[j],T[j-1]);
                for (int j=suf+1;j>1;--j,++cnt) swap(T[j],T[j-1]);
            }
        }
        for (int j=n-1;j>=0;--j) if (T[j]!='0'){
            for (int k=j;k<n-1;++k,++cnt) swap(T[k],T[k+1]);
            break;
        }
        int ok=0;
        for (int j=0;j<4;++j){
            if (T[0]=='0'+v[j][0]&&T[1]=='0'+v[j][1]) ok=1;
        }
        if (ok) chmin(ans,cnt);
    }
    cout << (ans==INF?-1:ans) << '\n';
}