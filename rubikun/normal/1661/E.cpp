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
const int mod=998244353,MAX=32768,INF=1<<30;

struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

//Wavelet matrix

// https://kopricky.github.io/code/DataStructure_Advanced/wavelet_matrix.html

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
    
    int N;cin>>N;
    UF uf;uf.init(3*N);
    UF A,B;A.init(N);B.init(N);
    vector<string> S(3);
    for(int i=0;i<3;i++) cin>>S[i];
    vector<int> T;
    vector<int> L(3*N,INF),R(3*N,INF);
    vector<int> use;
    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            if(S[i][j]=='1'){
                if(j+1<N&&S[i][j+1]=='1') uf.unite(i*N+j,i*N+j+1);
                if(i+1<3&&S[i+1][j]=='1') uf.unite(i*N+j,(i+1)*N+j);
            }
            if(i==0){
                if(S[i][j]=='1'&&j+1<N&&S[i][j+1]=='1') A.unite(j,j+1);
            }
            if(i==2){
                if(S[i][j]=='1'&&j+1<N&&S[i][j+1]=='1') B.unite(j,j+1);
            }
        }
    }
    for(int j=0;j<N;j++){
        for(int i=0;i<3;i++){
            if(S[i][j]=='1'&&L[uf.root(i*N+j)]==INF) L[uf.root(i*N+j)]=j;
        }
        if(S[0][j]=='1'&&S[1][j]=='1'&&S[2][j]=='1') T.push_back(j);
    }
    for(int j=N-1;j>=0;j--){
        for(int i=0;i<3;i++){
            if(S[i][j]=='1'&&R[uf.root(i*N+j)]==INF) R[uf.root(i*N+j)]=j;
            if(S[i][j]=='1'&&uf.root((i*N+j))==(i*N+j)) use.push_back(i*N+j);
        }
    }
    
    vector<pair<int,int>> def;
    for(auto a:use){
        def.push_back(mp(L[a],R[a]));
        //cout<<L[a]<<" "<<R[a]<<endl;
    }
    
    OrthogonalRangeCount<int> WM(def);
    
    int Q;cin>>Q;
    while(Q--){
        int l,r;cin>>l>>r;l--;
        int res=WM.query(0,l,r,N);
        //cout<<res<<" ";
        int a=0;
        if(S[0][l]=='1'&&S[1][l]=='0'&&S[2][l]=='1'){
            //cout<<'x';
            if(uf.check(0*N+l,2*N+l)){
                auto it=lower_bound(all(T),l);
                if(it!=T.end()&&(*it)<r&&A.check(0*N+l,0*N+(*it))&&B.check(l,(*it))){
                    
                }else{
                    //cout<<'x';
                    res++;
                    a++;
                }
            }
        }
        if(S[0][r-1]=='1'&&S[1][r-1]=='0'&&S[2][r-1]=='1'){
            if(uf.check(0*N+r-1,2*N+r-1)){
                auto it=lower_bound(all(T),r-1);
                if(it!=T.begin()){
                    it--;
                    //cout<<(*it);
                    if((*it)>=l&&A.check(0*N+r-1,0*N+(*it))&&B.check(r-1,(*it))){
                        
                    }else{
                        //cout<<'x';
                        res++;
                        a++;
                    }
                }else{
                    res++;
                    a++;
                }
            }
        }
        //cout<<res<<" ";
        if(a==2){
            if(A.check(l,r-1)&&B.check(l,r-1)) res--;
        }
        cout<<res<<"\n";
    }
}