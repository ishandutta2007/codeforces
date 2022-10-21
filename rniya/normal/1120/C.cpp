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

struct SuffixArray{
    string s;
    vector<int> SA;
    SuffixArray(const string &S):s(S){
        int n=s.size();
        s.push_back('$');
        SA.resize(n+1);
        iota(SA.begin(),SA.end(),0);
        sort(SA.begin(),SA.end(),[&](int a,int b){
            return s[a]==s[b]?a>b:s[a]<s[b];
        });
        vector<int> c(s.begin(),s.end()),cnt(n+1),nxt(n+1);
        for (int j=1;j<=n;j<<=1){
            for (int i=0;i<=n;++i){
                nxt[SA[i]]=((i&&c[SA[i-1]]==c[SA[i]]&&SA[i-1]+j<n&&c[SA[i-1]+j/2]==c[SA[i]+j/2])?nxt[SA[i-1]]:i);
            }
            iota(cnt.begin(),cnt.end(),0);
            copy(SA.begin(),SA.end(),c.begin());
            for (int i=0;i<=n;++i){
                if (c[i]-j>=0){
                    SA[cnt[nxt[c[i]-j]]++]=c[i]-j;
                }
            }
            nxt.swap(c);
        }
    }
    bool comp(const string &t,int si=0,int ti=0){
        int sn=s.size(),tn=t.size();
        for (;si<sn&&ti<tn;++si,++ti){
            if (s[si]<t[ti]) return true;
            if (s[si]>t[ti]) return false;
        }
        return si>=sn&&ti<tn;
    }
    int lower_bound(const string &t){
        int lb=-1,ub=SA.size();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (comp(t,SA[mid])?lb:ub)=mid;
        }
        return ub;
    }
    pair<int,int> lower_upper_bound(string &t){
        int l=lower_bound(t);
        int lb=l-1,ub=SA.size();
        ++t.back();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (comp(t,SA[mid])?lb:ub)=mid;
        }
        --t.back();
        return {l,ub};
    }
    int count(string &t){
        pair<int,int> p=lower_upper_bound(t);
        return p.second-p.first;
    }
    int operator[](int i) const {return SA[i];}
    int size() const {return s.size();}
};

struct LongestCommonPrefixArray{
    SuffixArray SA;
    vector<int> LCP,rank,lookup;
    vector<vector<int>> dat;
    LongestCommonPrefixArray(const string &s):SA(s){
        int n=s.size();
        LCP.resize(n); rank.resize(n+1);
        for (int i=0;i<=n;++i) rank[SA[i]]=i;
        LCP[0]=0;
        for (int i=0,t=0;i<n;++i){
            if (t) --t;
            for (int j=SA[rank[i]-1];max(i,j)+t<n&&s[i+t]==s[j+t];++t);
            LCP[rank[i]-1]=t;
        }
        int h=1;
        while((1<<h)<=n) ++h;
        dat.assign(h,vector<int>(n));
        lookup.assign(n+1,0);
        for (int i=2;i<=n;++i) lookup[i]=lookup[i>>1]+1;
        for (int j=0;j<n;++j) dat[0][j]=LCP[j];
        for (int i=1,mask=1;i<h;++i,mask<<=1){
            for (int j=0;j<n;++j){
                dat[i][j]=min(dat[i-1][j],dat[i-1][min(j+mask,n-1)]);
            }
        }
    }
    int query(int a,int b){
        if (a>b) swap(a,b);
        int d=lookup[b-a];
        return min(dat[d][a],dat[d][b-(1<<d)]);
    }
    // longest common prefix of s[a...] and s[b...]
    int lcp(int a,int b){
        return query(rank[a],rank[b]);
    }
    int operator[](int i) const {return LCP[i];}
    int size() const {return LCP.size();}
};

template<typename Monoid,typename OperatorMonoid>
struct LazySegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    typedef function<Monoid(Monoid,OperatorMonoid)> G;
    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)> H;
    int n,hi;
    F f;
    G g;
    H h;
    Monoid id0;
    OperatorMonoid id1;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    LazySegmentTree(int n_,F f,G g,H h,Monoid id0,OperatorMonoid id1):
                    f(f),g(g),h(h),id0(id0),id1(id1){init(n_);}
    void init(int n_){
        n=1,hi=0;
        while(n<n_) n<<=1,++hi;
        dat.assign(n<<1,id0);
        laz.assign(n<<1,id1);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    inline Monoid reflect(int k){
        return laz[k]==id1?dat[k]:g(dat[k],laz[k]);
    }
    inline void propagate(int k){
        if (laz[k]==id1) return;
        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);
        laz[k<<1|1]=h(laz[k<<1|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=id1;
    }
    inline void thrust(int k){
        for (int i=hi;i;--i) propagate(k>>i);
    }
    inline void recalc(int k){
        while(k>>=1) dat[k]=f(reflect(k<<1|0),reflect(k<<1|1));
    }
    void update(int a,int b,OperatorMonoid x){
        if (a>=b) return;
        thrust(a+=n); thrust(b+=n-1);
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) laz[l]=h(laz[l],x),++l;
            if (r&1) --r,laz[r]=h(laz[r],x);
        }
        recalc(a); recalc(b);
    }
    void set_val(int k,Monoid x){
        thrust(k+=n);
        dat[k]=x,laz[k]=id1;
        recalc(k);
    }
    Monoid query(int a,int b){
        if (a>=b) return id0;
        thrust(a+=n); thrust(b+=n-1);
        Monoid vl=id0,vr=id0;
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,reflect(l++));
            if (r&1) vr=f(reflect(--r),vr);
        }
        return f(vl,vr);
    }
    template<typename C>
    int find_subtree(int k,const C &check,Monoid &M,bool type){
        while(k<n){
            propagate(k);
            Monoid nxt=type?f(reflect(k<<1|type),M):f(M,reflect(k<<1|type));
            if (check(nxt)) k=k<<1|type;
            else M=nxt,k=k<<1|(type^1);
        }
        return k-n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template<typename C>
    int find_first(int a,const C &check){
        Monoid L=id0;
        if (a<=0){
            if (check(f(L,reflect(1)))) return find_subtree(1,check,L,false);
            return -1;
        }
        thrust(a+n);
        int b=n;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1){
                Monoid nxt=f(L,reflect(l));
                if (check(nxt)) return ffind_subtree(l,check,L,false);
                L=nxt; ++l;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template<typename C>
    int find_last(int b,const C &check){
        Monoid R=id0;
        if (b>=n){
            if (check(f(reflect(1),R))) return find_subtree(1,check,R,true);
            return -1;
        }
        thrust(b+n-1);
        int a=n;
        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){
            if (r&1){
                Monoid nxt=f(reflect(--r),R);
                if (check(nxt)) return find_subtree(r,check,R,true);
                R=nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i){return query(i,i+1);}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b; cin >> n >> a >> b;
    string S; cin >> S;

    LongestCommonPrefixArray LCP(S);

    auto f=[](int a,int b){return min(a,b);};
    LazySegmentTree<int,int> seg(n+1,f,f,f,INF,INF);
    seg.set_val(0,0);
    for (int i=0;i<n;++i){
        int cur=seg[i];
        seg.update(i+1,i+2,cur+a);
        for (int j=0;j<i;++j){
            int len=min(LCP.lcp(j,i),i-j);
            seg.update(i+1,i+1+len,cur+b);
        }
    }

    cout << seg[n] << '\n';
}