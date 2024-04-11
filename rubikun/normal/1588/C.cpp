#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

template<typename T>
struct SparseTable{
    using F=function<T(T,T)>;
    
    int n,logn;
    vector<vector<T>> dat;
    vector<int> loglen;
    F f;
    T ti;
    
    SparseTable(int n_,F f,T ti) :f(f),ti(ti){
        n=1;
        logn=1;
        while(n<n_){
            n*=2;
            logn++;
        }
        loglen.resize(n+3);
        n=n_;
        int j=0;
        for(int i=1;i<n+3;i++){
            loglen[i]=j;
            if(i+1>(1<<(j+1))) j++;
        }
        
        dat.resize(logn);
        
        for(int i=0;i<logn;i++){
            dat[i].assign(n+1,ti);
        }
    }
    
    void set(vector<T> &v){
        for(int j=0;j<n+1;j++){
            if(j<si(v)) dat[0][j]=v[j];
        }
    }
    
    void set(int j,T x){
        dat[0][j]=x;
    }
    
    void built(){
        for(int i=1;i<logn;i++){
            for(int j=0;j<n+1;j++){
                T vl=dat[i-1][j],vr;
                if(j+(1<<(i-1))>=n+1) vr=ti;
                else vr=dat[i-1][j+(1<<(i-1))];
                dat[i][j]=f(vl,vr);
            }
        }
    }
    
    T query(int l,int r){
        if(l>=r) return ti;
        T vl=dat[loglen[r-l]][l],vr=dat[loglen[r-l]][r-(1<<loglen[r-l])];
        return f(vl,vr);
    }
};

//Wavelet matrix

// from: https://kopricky.github.io/code/DataStructure_Advanced/wavelet_matrix.html

struct BitRank {
    // block: bit , count: block  1 
    vector<unsigned long long> block;
    vector<unsigned int> count;
    BitRank(){}
    void resize(const unsigned int num){
        block.resize(((num + 1) >> 6) + 1, 0);
        count.resize(block.size(), 0);
    }
    // i  val(0,1) 
    void set(const unsigned int i, const unsigned long long val){
        block[i >> 6] |= (val << (i & 63));
    }
    void build(){
        for(unsigned int i = 1; i < block.size(); i++){
            count[i] = count[i - 1] + __builtin_popcountll(block[i - 1]);
        }
    }
    // [0, i)  1 
    unsigned int rank1(const unsigned int i) const {
        return count[i >> 6] +
        __builtin_popcountll(block[i >> 6] & ((1ULL << (i & 63)) - 1ULL));
    }
    // [i, j)  1 
    unsigned int rank1(const unsigned int i, const unsigned int j) const {
        return rank1(j) - rank1(i);
    }
    // [0, i)  0 
    unsigned int rank0(const unsigned int i) const {
        return i - rank1(i);
    }
    // [i, j)  0 
    unsigned int rank0(const unsigned int i, const unsigned int j) const {
        return rank0(j) - rank0(i);
    }
};

class WaveletMatrix
{
private:
    unsigned int height;
    vector<BitRank> B;
    vector<int> pos;
public:
    WaveletMatrix(){}
    WaveletMatrix(vector<int> vec) :
    WaveletMatrix(vec, *max_element(vec.begin(), vec.end()) + 1){}
    // sigma:
    WaveletMatrix(vector<int> vec, const unsigned int sigma){
        init(vec, sigma);
    }
    void init(vector<int>& vec, const unsigned int sigma){
        height = (sigma == 1) ? 1 : (64 - __builtin_clzll(sigma - 1));
        B.resize(height), pos.resize(height);
        for(unsigned int i = 0; i < height; ++i){
            B[i].resize(vec.size());
            for(unsigned int j = 0; j < vec.size(); ++j) {
                B[i].set(j, get(vec[j], height - i - 1));
            }
            B[i].build();
            auto it = stable_partition(vec.begin(), vec.end(), [&](int c){
                return !get(c, height - i - 1);
            });
            pos[i] = it - vec.begin();
        }
    }
    // val  i (0,1)
    int get(const int val, const int i){
        return val >> i & 1;
    }
    // [l, r)  val 
    int rank(const int val, const int l, const int r){
        return rank(val, r) - rank(val, l);
    }
    // [0, i)  val 
    int rank(int val, int i){
        int p = 0;
        for(unsigned int j = 0; j < height; ++j){
            if(get(val, height - j - 1)){
                p = pos[j] + B[j].rank1(p);
                i = pos[j] + B[j].rank1(i);
            }else{
                p = B[j].rank0(p);
                i = B[j].rank0(i);
            }
        }
        return i - p;
    }
    // [l, r)  k(0,1,2...) 
    int quantile(int k, int l, int r){
        int res = 0;
        for(unsigned int i = 0; i < height; ++i){
            const int j = B[i].rank0(l, r);
            if(j > k){
                l = B[i].rank0(l);
                r = B[i].rank0(r);
            }else{
                l = pos[i] + B[i].rank1(l);
                r = pos[i] + B[i].rank1(r);
                k -= j;
                res |= (1 << (height - i - 1));
            }
        }
        return res;
    }
    int rangefreq(const int i, const int j, const int a, const int b,
                  const int l, const int r, const int x){
        if(i == j || r <= a || b <= l) return 0;
        const int mid = (l + r) >> 1;
        if(a <= l && r <= b){
            return j - i;
        }else{
            const int left = rangefreq(B[x].rank0(i), B[x].rank0(j), a, b, l, mid, x + 1);
            const int right = rangefreq(pos[x] + B[x].rank1(i), pos[x] + B[x].rank1(j),
                                        a, b, mid, r, x + 1);
            return left + right;
        }
    }
    // [l,r)  [a,b) 
    int rangefreq(const int l, const int r, const int a, const int b){
        return rangefreq(l, r, a, b, 0, 1 << height, 0);
    }
    int rangemin(const int i, const int j, const int a, const int b,
                 const int l, const int r, const int x, const int val){
        if(i == j || r <= a || b <= l) return -1;
        if(r - l == 1) return val;
        const int mid = (l + r) >> 1;
        const int res = rangemin(B[x].rank0(i),B[x].rank0(j),a,b,l,mid,x+1,val);
        if(res < 0) return rangemin(pos[x] + B[x].rank1(i), pos[x] + B[x].rank1(j),
                                    a, b, mid, r, x + 1, val + (1 << (height - x - 1)));
        else return res;
    }
    // [l,r)  [a,b) ( -1 )
    int rangemin(int l, int r, int a, int b){
        return rangemin(l, r, a, b, 0, 1 << height, 0, 0);
    }
};

template<typename T> class OrthogonalRangeCount
{
private:
    using ptt = pair<T, T>;
    const int sz;
    vector<T> X, Y;
    WaveletMatrix wm;
    
public:
    OrthogonalRangeCount(vector<ptt> candidate)
    : sz((int)candidate.size()), X(sz), Y(sz){
        sort(candidate.begin(), candidate.end());
        vector<int> vec(sz);
        for(int i = 0; i < sz; ++i){
            X[i] = candidate[i].first, Y[i] = candidate[i].second;
        }
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());
        for(int i = 0; i < sz; ++i){
            vec[i] = lower_bound(Y.begin(), Y.end(), candidate[i].second) - Y.begin();
        }
        wm.init(vec, Y.size());
    }
    // [lx,rx)  [ly, ry) 
    int query(const T lx, const T ly, const T rx, const T ry){
        const int lxid = lower_bound(X.begin(), X.end(), lx) - X.begin();
        const int rxid = lower_bound(X.begin(), X.end(), rx) - X.begin();
        const int lyid = lower_bound(Y.begin(), Y.end(), ly) - Y.begin();
        const int ryid = lower_bound(Y.begin(), Y.end(), ry) - Y.begin();
        if(lxid >= rxid || lyid >= ryid) return 0;
        return wm.rangefreq(lxid, rxid, lyid, ryid);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        if(N==1){
            if(A[0]==0) cout<<1<<"\n";
            else cout<<0<<"\n";
            continue;
        }
        vector<ll> rui(N+1);
        for(int i=1;i<=N;i++){
            rui[i]=rui[i-1];
            if(i&1) rui[i]-=A[i-1];
            else rui[i]+=A[i-1];
        }
        vector<pair<ll,ll>> def0,def1;
        for(int i=0;i<=N;i++){
            if(i%2==0) def0.push_back(mp(rui[i],rui[i]));
            else def1.push_back(mp(rui[i],rui[i]));
        }
        
        SparseTable<pair<ll,ll>> spa0(si(def0),[](pair<ll,ll> a,pair<ll,ll> b){return mp(max(a.fi,b.fi),min(a.se,b.se));},mp(-INF,INF));
        SparseTable<pair<ll,ll>> spa1(si(def1),[](pair<ll,ll> a,pair<ll,ll> b){return mp(max(a.fi,b.fi),min(a.se,b.se));},mp(-INF,INF));
        spa0.set(def0);
        spa1.set(def1);
        spa0.built();
        spa1.built();
        
        vector<ll> use=rui;
        sort(all(use));
        use.erase(unique(all(use)),use.end());
        
        auto zip=[&](ll x){
            return (int)(lower_bound(all(use),x)-use.begin());
        };
        vector<int> zaatu(N+1);
        for(int i=0;i<=N;i++){
            zaatu[i]=zip(rui[i]);
        }
        
        WaveletMatrix WM(zaatu);
        
        ll ans=0;
        
        for(int i=0;i<N-1;i++){
            int l=i/2,r=N/2+1;
            while(r-l>1){
                int m=(l+r)/2;
                auto x=spa0.query((i+1)/2,m+1);
                if(x.se<rui[i]) r=m;
                else l=m;
            }
            int sl=l;
            int ss=(i-1)/2;
            if(i==0) ss=-1;
            l=ss;r=(N+1)/2;
            while(r-l>1){
                int m=(l+r)/2;
                auto x=spa1.query(i/2,m+1);
                if(x.fi>rui[i]) r=m;
                else l=m;
            }
            int tl=l;
            int ok=min(sl*2+1,tl*2+1+1);
            if(ok<=i+1) continue;
            ll X=WM.rank(zaatu[i],i+2,ok+1);
            ans+=X;
        }
        for(int i=0;i<N;i++) if(A[i]==0) ans++;
        cout<<ans<<"\n";
    }
}