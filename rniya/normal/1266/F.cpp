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

const int MAX_N=5e5+10;
map<int,int> hist[MAX_N];
int ans[MAX_N],res[MAX_N],d[MAX_N],dp[MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    auto dfs1=[&](auto self,int v,int p)->void{
        if (p<0) d[v]=0;
        dp[v]=0;
        for (int u:G[v]){
            if (u==p) continue;
            d[u]=d[v]+1;
            self(self,u,v);
            dp[v]=max(dp[v],dp[u]+1);
        }
    };
    auto update_vertex=[&](vector<int> v){
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int s=v.size();
        for (int i=s-1;i>0;--i){
            if (v[i-1]>v[i]) ans[2*v[i]+1]=max(ans[2*v[i]+1],i+1);
            else ans[2*v[i]]=max(ans[2*v[i]],i+1);
        }
    };
    auto update_edge=[&](const map<int,int> &mp1,const map<int,int> &mp2){
        int sum=0;
        auto itr2=mp2.rbegin();
        for (auto itr1=mp1.rbegin();itr1!=mp1.rend();++itr1){
            while(itr2!=mp2.rend()&&(itr1->first)<(itr2->first)){
                sum+=itr2->second;
                if (sum>1) res[(itr2->first)*2]=max(res[(itr2->first)*2],sum);
                ++itr2;
            }
            sum+=itr1->second;
            if (sum>1) res[(itr1->first)*2]=max(res[(itr1->first)*2],sum);
        }
        for (;itr2!=mp2.rend();++itr2){
            sum+=itr2->second;
            if (sum>1) res[(itr2->first)*2]=max(res[(itr2->first)*2],sum);
        }
    };
    auto dfs2=[&](auto self,int v,int p,int D)->void{
        vector<int> ds;
        int s=G[v].size();
        ans[1]=max(ans[1],s+1);
        for (int u:G[v]){
            ds.emplace_back(u==p?D:dp[u]+1);
            if (u!=p) ++hist[v][dp[u]+1];
        }
        update_vertex(ds);
        if (~p) update_edge(hist[v],hist[p]);
        ++hist[v][D];
        vector<int> left(s+1,0),right(s+1,0);
        for (int i=0;i<s;++i) left[i+1]=max(left[i],ds[i]);
        for (int i=s-1;i>=0;--i) right[i]=max(right[i+1],ds[i]);
        for (int i=0;i<s;++i){
            int u=G[v][i];
            if (u==p) continue;
            --hist[v][dp[u]+1];
            self(self,u,v,max(left[i],right[i+1])+1);
            ++hist[v][dp[u]+1];
        }
    };
    dfs1(dfs1,0,-1);
    dfs2(dfs2,0,-1,0);
    ans[n]=max(ans[n],1);
    for (int i=n-1;i>=1;--i) ans[i]=max(ans[i],ans[i+1]);
    for (int i=n;i>=1;--i){
        ans[i]=max(ans[i],res[i]);
        if (i+2<=n) ans[i]=max(ans[i],ans[i+2]);
    }
    for (int i=1;i<=n;++i) cout << ans[i] << (i==n?'\n':' ');
}