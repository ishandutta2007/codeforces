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

namespace FastFourierTransform{
    struct Complex{
        double x,y;
        Complex():x(0),y(0){}
        Complex(double x,double y):x(x),y(y){}
        inline Complex operator+(const Complex &c) const {
            return Complex(x+c.x,y+c.y);
        }
        inline Complex operator-(const Complex &c) const {
            return Complex(x-c.x,y-c.y);
        }
        inline Complex operator*(const Complex &c) const {
            return Complex(x*c.x-y*c.y,x*c.y+y*c.x);
        }
        inline Complex conj() const {return Complex(x,-y);}
    };
    const double PI=acosl(-1);
    vector<Complex> roots={{0,0},{1,0}};
    vector<int> rev={0,1};
    int base=1;
    void ensure_base(int nbase){
        if (nbase<=base) return;
        rev.resize(1<<nbase);
        for (int i=0;i<(1<<nbase);++i){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
        }
        roots.resize(1<<nbase);
        for (;base<nbase;++base){
            double angle=PI*2.0/(1<<(base+1));
            for (int i=1<<(base-1);i<(1<<base);++i){
                roots[i<<1]=roots[i];
                double angle_i=angle*((i<<1|1)-(1<<base));
                roots[i<<1|1]=Complex(cos(angle_i),sin(angle_i));
            }
        }
    }
    void fft(vector<Complex> &a,int n){
        int zeros=__builtin_ctz(n);
        ensure_base(zeros);
        int shift=base-zeros;
        for (int i=0;i<n;++i){
            if (i<(rev[i]>>shift)){
                swap(a[i],a[rev[i]>>shift]);
            }
        }
        for (int k=1;k<n;k<<=1){
            for (int i=0;i<n;i+=(k<<1)){
                for (int j=0;j<k;++j){
                    Complex z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }
    vector<int> multiply(const vector<int> &a,const vector<int> &b){
        int need=a.size()+b.size()-1;
        int nbase=1;
        while((1<<nbase)<need) ++nbase;
        ensure_base(nbase);
        int sz=1<<nbase;
        vector<Complex> C(sz);
        for (int i=0;i<sz;++i){
            int x=(i<a.size()?a[i]:0);
            int y=(i<b.size()?b[i]:0);
            C[i]=Complex(x,y);
        }
        fft(C,sz);
        Complex r(0,-0.25/(sz>>1)),s(0,1),t(0.5,0);
        for (int i=0;i<=(sz>>1);++i){
            int j=(sz-i)&(sz-1);
            Complex z=(C[j]*C[j]-(C[i]*C[i]).conj())*r;
            C[j]=(C[i]*C[i]-(C[j]*C[j]).conj())*r;
            C[i]=z;
        }
        for (int i=0;i<(sz>>1);++i){
            Complex C0=(C[i]+C[i+(sz>>1)])*t;
            Complex C1=(C[i]-C[i+(sz>>1)])*t*roots[(sz>>1)+i];
            C[i]=C0+C1*s;
        }
        fft(C,sz>>1);
        vector<int> res(need);
        for (int i=0;i<need;++i){
            res[i]=round(i&1?C[i>>1].y:C[i>>1].x);
        }
        return res;
    }
}

const int MAX_L=1e6+10,MAX_N=2e5+10;
vector<int> dp[MAX_N][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x,y; cin >> n >> x >> y;
    vector<int> a(n+1); cin >> a;

    vector<int> ok(MAX_N,0);
    for (int i=0;i<n;++i){
        for (int j=0;j<2;++j){
            dp[i][j].emplace_back(1);
            for (int k=1;k<a[i+1]-a[i];++k) dp[i][j].emplace_back(0);
            dp[i][j].emplace_back(1);
        }
        ok[a[i+1]-a[i]]=1;
    }

    auto dfs=[&](auto self,int l,int r)->vector<vector<int>>{
        if (r-l==1) return {dp[l][0],dp[l][1]};
        int mid=(l+r)>>1;
        vector<int> L,R;
        for (int i=0;i<a[mid]-a[l];++i) L.emplace_back(0);
        L.emplace_back(1);
        for (int i=0;i<a[r]-a[mid];++i) R.emplace_back(0);
        R.emplace_back(1);
        vector<vector<int>> dpl=self(self,l,mid),dpr=self(self,mid,r);
        vector<vector<int>> res(2);
        res[0]=FastFourierTransform::multiply(L,dpr[0]);
        for (int i=0;i<dpl[0].size();++i) res[0][i]+=dpl[0][i];
        res[1]=FastFourierTransform::multiply(dpl[1],R);
        for (int i=0;i<dpr[1].size();++i) res[1][i]+=dpr[1][i];
        vector<int> v=FastFourierTransform::multiply(dpl[1],dpr[0]);
        for (int i=1;i<v.size();++i){
            if (v[i]>0) ok[i]=1;
        }
        return res;
    };

    dfs(dfs,0,n);
    vector<int> ans(MAX_L,-1);
    for (int i=1;i<MAX_N;++i){
        if (!ok[i]) continue;
        int L=2*(y+i);
        for (int j=L;j<MAX_L;j+=L) ans[j]=L;
    }

    int q; cin >> q;
    for (;q--;){
        int l; cin >> l;
        cout << ans[l] << (!q?'\n':' ');
    }
}