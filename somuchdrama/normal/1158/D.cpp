#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _dbg(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_dbg(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=2019;
#define DEFAULTCLASS int
#define sqr(x)((x)*(x))
const double EPS=1e-9,PI=3.1415926535897932384626433;
struct myf{
    double x;
    myf()=default;
    myf(double _x):x(_x){}
    myf operator+(const myf&rhs){return x+rhs.x;}
    myf operator-(const myf&rhs){return x-rhs.x;}
    myf operator-(){return -x;}
    myf operator*(const myf&rhs){return x*rhs.x;}
    myf operator/(const myf&rhs){return x/rhs.x;}
    bool operator<(const myf&rhs)const{return x+EPS<rhs.x;}
    bool operator>(const myf&rhs)const{return x>rhs.x+EPS;}
    bool operator==(const myf&rhs)const{return abs(x-rhs.x)/max(1.,abs(x))<=EPS;}
    bool operator!=(const myf&rhs)const{return abs(x-rhs.x)/max(1.,abs(x))>EPS;}
    bool operator<=(const myf&rhs)const{return *this<rhs||*this==rhs;}
    bool operator>=(const myf&rhs)const{return *this>rhs||*this==rhs;}
};
myf sqrt(myf x){return sqrt(x.x);}
myf abs(myf x){if(x.x<0)return -x;return x;}
std::istream&operator>>(std::istream&is,myf&p){return is>>p.x;}
std::ostream&operator<<(std::ostream&os,myf&p){return os<<p.x;}
template<class T=DEFAULTCLASS> struct pt{
    T x,y;
    int i;
    pt(){}
    pt(T _x,T _y): x(_x),y(_y){}
    bool operator<(const pt&rhs)const{
        return x==rhs.x?y<rhs.y:x<rhs.x;
    }
    bool operator==(const pt&rhs)const{
        return x==rhs.x&&y==rhs.y;
    }
};
template<class T>T dist(pt<T>a,pt<T>b){return sqrt(sqr(b.x-a.x)+sqr(b.y-a.y));}
template<class T>T sqdist(pt<T>a,pt<T>b){return sqr(b.x-a.x)+sqr(b.y-a.y);}
template<class T>std::istream&operator>>(std::istream&is,pt<T>&p){return is>>p.x>>p.y;}
template<class T>std::ostream&operator<<(std::ostream&os,pt<T>&p){return os<<p.x<<' '<<p.y;}
template<class T=DEFAULTCLASS> struct vc{
    T x,y;
    vc(){}
    vc(T _x,T _y): x(_x),y(_y){}
    vc(pt<T>a,pt<T>b){
        x=b.x-a.x;
        y=b.y-a.y;
    }
    T length(){return sqrt(sqr(x)+sqr(y));}
    T sqlength(){return sqr(x)+sqr(y);}
    vc operator +(vc b){return vc(x+b.x,y+b.y);}
    T operator *(vc b){return x*b.x+y*b.y;}
    T operator %(vc b){return x*b.y-y*b.x;}
    vc operator *(T k){return vc(x*k,y*k);}
    vc rotate(double angle){return vc(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));}
};
#define pt pt<>
pt a[N],o;
int u[N];
bool cmp(const pt&p1,const pt&p2){
    return vc(o,p1)%vc(o,p2)>0;
}
int32_t main() {

    int n;
    cin>>n;
    forn(i,n){cin>>a[i];a[i].i=i;}
    string s;
    cin>>s;
    sort(a,a+n);
    vector<pt> ans;
    o=a[0];
    u[o.i]=1;
    ans.pb(o);
    dbg(o.i);
    forn(i,n-2){
        vector<pt> pts;
        forn(j,n)if(!u[a[j].i])pts.pb(a[j]);
        sort(pts.begin(),pts.end(),cmp);
        pt go;
        if(s[i]=='L')go=pts[0];
        else go=pts.back();
        ans.pb(o=go);
        u[o.i]=1;
        dbg(o.i);
    }
    forn(i,n)if(!u[a[i].i])ans.pb(a[i]);
    string t;
    for(int i=1;i<n-1;++i){
        if(vc(ans[i-1],ans[i])%vc(ans[i],ans[i+1])>0)t+='L';
        else t+='R';
    }
    if(s!=t){
        cout<<"-1\n";
        return 0;
    }
    for(pt&i:ans)cout<<i.i+1<<' ';
    cout<<'\n';

    return 0;
}