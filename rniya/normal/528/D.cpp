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
    vector<long long> multiply(const vector<int> &a,const vector<int> &b){
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
        vector<long long> res(need);
        for (int i=0;i<need;++i){
            res[i]=llround(i&1?C[i>>1].y:C[i>>1].x);
        }
        return res;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,K; cin >> n >> m >> K;
    string s,t; cin >> s >> t;

    auto ctoi=[](char c){
        if (c=='A') return 0;
        if (c=='T') return 1;
        if (c=='G') return 2;
        return 3;
    };
    vector<int> S(n),T(m);
    for (int i=0;i<n;++i) S[i]=ctoi(s[i]);
    for (int i=0;i<m;++i) T[i]=ctoi(t[i]);
    reverse(T.begin(),T.end());
    auto solve=[&](int x){
        int cnt=0;
        for (int i=0;i<=K;++i) cnt+=(S[i]==x);
        vector<int> A(n),B(m);
        for (int i=0;i<n;++i){
            A[i]=(cnt>0);
            if (i+K+1<n) cnt+=(S[i+K+1]==x);
            if (i-K>=0) cnt-=(S[i-K]==x);
        }
        for (int i=0;i<m;++i) B[i]=(T[i]==x);
        int sum=accumulate(B.begin(),B.end(),0);
        vector<ll> C=FastFourierTransform::multiply(A,B);
        vector<bool> res(n);
        for (int i=0;i<n;++i) res[i]=(C[i+m-1]==sum);
        return res;
    };
    vector<bool> ok(n,true);
    for (int j=0;j<4;++j){
        vector<bool> v=solve(j);
        for (int i=0;i<n;++i){
            if (!v[i]){
                ok[i]=false;
            }
        }
    }

    int ans=0;
    for (int i=0;i<n;++i) ans+=ok[i];
    cout << ans << '\n';
}