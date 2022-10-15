#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...) 
#endif
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
mt19937 rng(300);

const double EPS=1e-9;//long double?
const double PI=3.1415926535897932384626433; //long double?
struct myf{
    double x; //long double?
    myf()=default;
    myf(double _x):x(_x){}
    myf operator-()const{return -x;}
    myf operator+(const myf&rhs)const{return x+rhs.x;}
    myf operator-(const myf&rhs)const{return x-rhs.x;}
    myf operator*(const myf&rhs)const{return x*rhs.x;}
    myf operator/(const myf&rhs)const{return x/rhs.x;}
    myf& operator+=(const myf&rhs){x+=rhs.x;return*this;}
    myf& operator-=(const myf&rhs){x-=rhs.x;return*this;}
    myf& operator*=(const myf&rhs){x*=rhs.x;return*this;}
    myf& operator/=(const myf&rhs){x/=rhs.x;return*this;}
    bool operator<(const myf&rhs)const{return x+EPS<rhs.x;}
    bool operator>(const myf&rhs)const{return x>rhs.x+EPS;}
    bool operator==(const myf&rhs)const{return abs(x-rhs.x)/max(1.,abs(x))<=EPS;}//ld1
    bool operator!=(const myf&rhs)const{return abs(x-rhs.x)/max(1.,abs(x))>EPS;}//ld1
    bool operator<=(const myf&rhs)const{return*this<rhs||*this==rhs;}
    bool operator>=(const myf&rhs)const{return*this>rhs||*this==rhs;}
};
myf sqrt(myf x){return sqrt(x.x);}
myf abs(myf x){if(x.x<0)return -x;return x;}
std::istream&operator>>(std::istream&is,myf&p){return is>>p.x;}
std::ostream&operator<<(std::ostream&os,myf&p){return os<<p.x;}
template<class T>struct vc{
    T x,y;
    int i;
    vc(){}
    vc(T _x,T _y): x(_x),y(_y){}
    bool operator<(const vc&rhs)const{return x==rhs.x?y<rhs.y:x<rhs.x;}
    bool operator==(const vc&rhs)const{return x==rhs.x&&y==rhs.y;}
    vc(vc<T>a,vc<T>b){x=b.x-a.x;y=b.y-a.y;}
    T length()const{return sqrt(sqr(x)+sqr(y));}
    T sqlength()const{return sqr(x)+sqr(y);}
    vc operator +(const vc&b)const{return vc(x+b.x,y+b.y);}
    vc operator -(const vc&b)const{return vc(x-b.x,y-b.y);}
    T operator *(const vc&b)const{return x*b.x+y*b.y;}
    T operator %(const vc&b)const{return x*b.y-y*b.x;}
    vc operator *(const T k)const{return vc(x*k,y*k);}
    vc rotate(const double angle)const{return vc(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));}
    bool hpl()const{return y>0||(y==0&&x>=0);}
};
template<class T>ld dist(vc<T>a,vc<T>b){return sqrtl(sqr(b.x-a.x)+sqr(b.y-a.y));}
template<class T>T sqdist(vc<T>a,vc<T>b){return sqr(b.x-a.x)+sqr(b.y-a.y);}
template<class T>std::istream&operator>>(std::istream&is,vc<T>&p){return is>>p.x>>p.y;}
template<class T>std::ostream&operator<<(std::ostream&os,vc<T>&p){return os<<p.x<<' '<<p.y;}
template<class T>vc<T>turn_clockwise(vc<T>a){return vc<T>(a.y,-a.x);}
template<class T>vc<T>turn_anticlockwise(vc<T>a){return vc<T>(-a.y,a.x);}
template<class T>struct line
{
    T a,b,c;
    line(){}
    line(T _a,T _b,T _c): a(_a),b(_b),c(_c){
        //normalize();
    }
    line(vc<T>one,vc<T>two){
        a=one.y-two.y;
        b=two.x-one.x;
        c=-(a*one.x+b*one.y);
        //normalize();
    }
    line(vc<T>norm,vc<T>cont,int mycop){
        a=norm.x;
        b=norm.y;
        c=-(a*cont.x+b*cont.y);
        //normalize();
    }
    void normalize(){
        T div=sqrt(sqr(a)+sqr(b));
        a/=div;
        b/=div;
        c/=div;
    }
    void gcd_normalize(){
        T div=gcd(gcd(a,b),c);
        a/=div;
        b/=div;
        c/=div;
    }
    bool on(vc<T>p){return a*p.x+b*p.y+c==0;}
};
template<class T>struct circle{
    vc<T>center;T radius;
    circle(){}
    circle(vc<T>_center,T _radius):center(_center),radius(_radius){}
    circle(vc<T>_center,vc<T>_v):center(_center){radius=_v.length();}
    bool inside(vc<T>p){return dist(p,center)<=radius;}
    bool strict_inside(vc<T>p){return dist(p,center)<radius;}
    bool on(vc<T>p){return dist(p,center)==radius;}
};
template<class T>T vc_segment_dist(vc<T>O,vc<T>p1,vc<T>p2){ // vc O,segment [p1,p2]
    return((vc<T>(p1,O)*vc(p1,p2))*(vc(p2,p1)*vc(p2,O))<=0)?min(dist(O,p1),dist(O,p2)):abs((vc(O,p1)%vc(O,p2))/dist(p1,p2));
}
template<class T>T det(T a,T b,T c,T d){return a*d-b*c;}
// 0 if parallel;{1,vc} if OK; 2 if match.
template<class T>int cross(line<T>one,line<T>two,vc<T>&p){ 
    T dx=det(one.c,one.b,two.c,two.b),dy=det(one.a,one.c,two.a,two.c),dd=det(one.a,one.b,two.a,two.b);
    if(dx==0&&dy==0&&dd==0)return 2;
    else if(dd==0)         return 0;
    p=vc(-dx/dd,-dy/dd);   return 1;
}
// 0 if A in C;{1,vc} if A on C;{2,vc,vc} if OK
template<class T>int kasat(vc<T>A,circle<T>C,vc<T>&p1,vc<T>&p2){ 
    vc OA(C.center,A);
    T l=OA.length();
    if(l<C.radius)return 0;
    T x=sqr(C.radius)/l;
    vc OP(OA.x*x/l,OA.y*x/l);
    vc P=C.center+OP;
    T hor=sqrt(sqr(C.radius)-OP.sqlength());
    p1=P+turn_clockwise(OP*(hor/x));
    p2=P+turn_anticlockwise(OP*(hor/x));
    return l==C.radius?1:2;
}
// 0 no intersection; 1/2=OK(1/2 vcs)
template<class T>int cross(line<T>l,circle<T>c,vc<T>&p1,vc<T>&p2){ 
    if(l.b==0){
        p1.x=-l.c/l.a;
        if(sqr(c.radius)>=sqr(p1.x-c.center.x)){
            p2.x=p1.x;
            p1.y=c.center.y+sqrt(max(T(0),sqr(c.radius)-sqr(c.center.x-p1.x)));
            p2.y=c.center.y-sqrt(max(T(0),sqr(c.radius)-sqr(c.center.x-p1.x)));
            return sqr(c.radius)==sqr(c.center.x-p1.x)?1:2;
        }
        return 0;
    }
    T tt=(l.c+l.b*c.center.y)/l.b;
    T ta=sqr(l.a/l.b)+1,tb=(tt*l.a/l.b-c.center.x)*2,tc=sqr(tt)-sqr(c.radius)+sqr(c.center.x);
    T td=sqr(tb)-ta*tc*4;
    if(td<0)return 0;
    p1.x=(-tb+sqrt(max(T(0),td)))/(ta+ta); 
    p2.x=(-tb-sqrt(max(T(0),td)))/(ta+ta);
    p1.y=(-l.c-l.a*p1.x)/l.b;
    p2.y=(-l.c-l.a*p2.x)/l.b;
    return td==0?1:2;
}
// 0 no intersection; 1/2=OK(1/2 vcs); 3=match
template<class T>int cross(circle<T>one,circle<T>two,vc<T>&p1,vc<T>&p2){ 
    if(one.center.x==two.center.x&&one.center.y==two.center.y)return one.radius==two.radius?3:0;
    line l((two.center.x-one.center.x)*2,(two.center.y-one.center.y)*2,sqr(one.center.x)-sqr(two.center.x)+sqr(one.center.y)-sqr(two.center.y)+sqr(two.radius)-sqr(one.radius));
    return cross(l,one,p1,p2);
}
// !!!a[0]==a.back(),vcs anticlockwise
template<class T>bool inside_convex_polygon(const vector<vc<T>>&a,vc<T>p){  
    int n=a.size()-1,l=1,r=a.size()-2;
    vc cur(a[0],p);
    if(vc(a[0],a[1])%cur<0||cur%vc(a[0],a[n-1])<0)return 0;
    while(r-l>1){
        int m=(l+r)/2;
        if(cur%vc(a[0],a[m])>=0)r=m;
        else l=m;
    }
    return vc(a[r],p)%vc(a[r],a[r+1])<=0&&vc(a[r-1],p)%vc(a[r-1],a[r])<=0;
}
template<class T>T area(const vector<vc<T>>&p){
    T res=0;
    for(int i=1;i+1<p.size();++i)res+=vc(p[0],p[i])%vc(p[0],p[i+1]);
    return abs(res);
}

template<class T>bool btw(T o,T d1,T d2){return(d1<o&&o<d2)||(d2<o&&o<d1);}
template<class T>bool pbtw(vc<T>o,vc<T>p1,vc<T>p2){return btw(o.x,p1.x,p2.x)&&btw(o.y,p1.y,p2.y);}
#define vc vc<int>

const int N=201010;
vc a[N];
int32_t main(){

    int n,k;
    cin>>n>>k;
    --k;
    forn(i,n){
        cin>>a[i];
        a[i].i=i;
    }
    if(n==3){
        int x=0,y=0;
        while(x==k)x++;
        while(y==k||y==x)y++;
        cout<<min(dist(a[k],a[y]),dist(a[k],a[x]))+dist(a[x],a[y])<<'\n';
        return 0;
    }
    line<int> l;
    while(1){
        int x=rng()%n,y=rng()%n,z=rng()%n;
        if(x==y)continue;
        if(x==z)continue;
        if(y==z)continue;
        if((a[x]-a[y])%(a[x]-a[z])!=0)continue;
        l=line(a[x],a[y]);
        break;
    }
    vc perp(l.b,-l.a);
    sort(a,a+n,[&](const vc&p1,const vc&p2){
        int r1=p1*perp;
        int r2=p2*perp;
        return r1<r2;
    });

    int out=0,gde_k=-1;
    forn(i,n){
        if(a[i].x*l.a+a[i].y*l.b!=-l.c)out=i;
        if(a[i].i==k)gde_k=i;
    }
    vector<pii> v;
    v.pb(0,0);
    v.pb(gde_k,0);
    if(gde_k>=1)v.pb(gde_k-1,0);
    if(gde_k+1<n)v.pb(gde_k+1,0);
    v.pb(out,0);
    if(out>=1)v.pb(out-1,0);
    if(out>=2)v.pb(out-2,0);
    if(out+2<n)v.pb(out+2,0);
    if(out+1<n)v.pb(out+1,0);
    v.pb(n-1,0);
    sort(all(v));
    v.resize(unique(all(v))-v.begin());

    vector<int> ux(sz(v)-1);
    forn(i,sz(v))v[i].s=i;
    forn(i,sz(v)-1){
        if(v[i].f==out||v[i+1].f==out||v[i].f+1==v[i+1].f)
            ux[i]=1;
    }

    forn(i,sz(v)){
        if(v[i].f==gde_k){
            rotate(v.begin(),v.begin()+i,v.begin()+i+1);
            break;
        }
    }

    ld ans=1e18;
    do{
        auto u=ux;
        ld cur=0;
        for(int i=1;i<sz(v);++i){
            cur+=dist(a[v[i-1].f],a[v[i].f]);
            if(v[i-1].f!=out&&v[i].f!=out){
                int x=v[i-1].s,y=v[i].s;
                if(x>y)swap(x,y);
                for(int j=x;j<y;++j)u[j]=1;
            }
        }
        int ok=1;
        for(int i:u)ok&=i;
        if(ok)upn(ans,cur);
    }while(next_permutation(1+all(v)));
    cout<<ans<<'\n';
    return 0;
}