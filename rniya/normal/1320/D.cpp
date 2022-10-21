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

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

struct RollingHash{
    static const int B1=1007,B2=2009;
    static const int mod1=1000000007,mod2=1000000009;
    vector<long long> hash1,hash2,po1,po2;
    RollingHash(const vector<long long> &vs){init(vs);}
    RollingHash(const string &S){
        vector<long long> vs;
        for (char c:S) vs.emplace_back(c);
        init(vs);
    }
    void init(vector<long long> vs){
        int n=vs.size();
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        po1.assign(n+1,1);
        po2.assign(n+1,1);
        for (int i=0;i<n;++i){
            hash1[i+1]=(hash1[i]*B1+vs[i])%mod1;
            hash2[i+1]=(hash2[i]*B2+vs[i])%mod2;
            po1[i+1]=po1[i]*B1%mod1;
            po2[i+1]=po2[i]*B2%mod2;
        }
    }
    inline pair<long long,long long> get(int l,int r) const{
        long long res1=hash1[r]+mod1-hash1[l]*po1[r-l]%mod1
                ,res2=hash2[r]+mod2-hash2[l]*po2[r-l]%mod2;
        return {res1>=mod1?res1-mod1:res1,res2>=mod2?res2-mod2:res2};
    }
    inline int LCP(int a,int b) const{
        int len=min((int)hash1.size()-a,(int)hash1.size()-b);
        int lb=0,ub=len;
        while(ub-lb>1){
            int mid=(lb+ub)>>1;
            (get(a,a+mid)==get(b,b+mid)?lb:ub)=mid;
        }
        return lb;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; string S; cin >> n >> S >> q;
    vector<int> seq(n+1,0),zero;
    string T="",U="";
    for (int i=0;i<n;++i){
        if (i&&S[i]=='1'&&S[i-1]=='1'){
            ++seq[i+1];
        }
        if (S[i]=='0'){
            zero.emplace_back(i);
            T+=('0'+(i&1));
            U+=('0'+((i^1)&1));
        }
    }
    for (int i=0;i<n;++i) seq[i+1]+=seq[i];
    RollingHash rh1(T),rh2(U),rh3(S);
    for (;q--;){
        int l,r,len; cin >> l >> r >> len; --l,--r;
        int cnt1=lower_bound(ALL(zero),l+len)-lower_bound(ALL(zero),l);
        int cnt2=lower_bound(ALL(zero),r+len)-lower_bound(ALL(zero),r);
        if (cnt1!=cnt2){
            cout << "No" << '\n';
            continue;
        }
        int s1=lower_bound(ALL(zero),l)-zero.begin();
        int s2=lower_bound(ALL(zero),r)-zero.begin();
        pair<ll,ll> p,q;
        if (l&1) p=rh1.get(s1,s1+cnt1);
        else p=rh2.get(s1,s1+cnt1);
        if (r&1) q=rh1.get(s2,s2+cnt2);
        else q=rh2.get(s2,s2+cnt2);
        int ok1=seq[l+len]-seq[l+1],ok2=seq[r+len]-seq[r+1];
        if (p==q&&ok1&&ok2){
            cout << "Yes" << '\n';
            continue;
        }
        cout << (rh3.get(l,l+len)==rh3.get(r,r+len)?"Yes":"No") << '\n';
    }
}