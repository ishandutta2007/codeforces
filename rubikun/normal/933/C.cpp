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
const int mod=998244353,MAX=200005,INF=1<<30;

//

const double eps=1e-8;
const double pi=acos((double)-1.0L);
#define equals(a,b) (fabs((a)-(b))<eps)

double torad(int deg) {return (double)(deg)*pi/180.0;}
double todeg(double ang) {return ang*180.0/pi;}

class Point{
public:
    double x,y;
    
    Point(double x=0,double y=0):x(x),y(y){}
    
    Point operator + (Point p){return Point(x+p.x,y+p.y);}
    Point operator - (Point p){return Point(x-p.x,y-p.y);}
    Point operator * (double a){return Point(a*x,a*y);}
    Point operator / (double a){return Point(x/a,y/a);}
    
    double abs(){return sqrt(norm());}
    double norm(){return x*x+y*y;}
    
    bool operator < (const Point &p)const{
        return x+eps<p.x||(equals(x,p.x)&&y+eps<p.y);
    }
    
    bool operator == (const Point &p)const{
        return fabs(x-p.x)<eps/100000&&fabs(y-p.y)<eps/100000;
    }
};

typedef Point Vector;

double norm(Vector a){
    return a.x*a.x+a.y*a.y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

double dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

struct Segment{
    Point p1,p2;
};

bool isOrthogonal(Vector a,Vector b){
    return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
    return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
    return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

bool isParallel(Vector a,Vector b){
    return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
    return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
    return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

Point project(Segment s,Point p){
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}

Point reflect(Segment s,Point p){
    return p+(project(s,p)-p)*2.0;
}

Point turn(Point p,Point c,double pi){
    double q=atan2(p.y-c.y,p.x-c.x);
    q+=pi;
    p=c+Point{cos(q)*abs(p-c),sin(q)*abs(p-c)};
    
    return p;
}
//pcpi(12)
//p=cnan

//p0,p1,p2

static const int counter_clockwise=1;
static const int clockwise=-1;
static const int online_back=2;
static const int online_front=-2;
static const int on_segment=0;

int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    
    if(cross(a,b)>eps) return counter_clockwise;
    if(cross(a,b)<-eps) return clockwise;
    if(dot(a,b)<-eps) return online_back;
    if(a.norm()<b.norm()) return online_front;
    
    return on_segment;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
    return(ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2){
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

bool overlap(Segment s1,Segment s2){
    int a=ccw(s1.p1,s1.p2,s2.p1),b=ccw(s1.p1,s1.p2,s2.p2);
    if(a&1||b&1) return 0;
    if(a==2){
        if(b==-2||(b==0&&!(s2.p2==s1.p1))) return 1;
        else return 0;
    }
    if(a==-2){
        if(b==2||(b==0&&!(s2.p2==s1.p2))) return 1;
        else return 0;
    }
    if(a==0){
        if(s1.p1==s2.p1){
            if(b!=2) return 1;
            else return 0;
        }
        else if(s1.p2==s2.p1){
            if(b!=-2) return 1;
            else return 0;
        }
        else return 1;
    }
    return 0;
}
//s1s2(0)

typedef Segment Line;

double getDistance(Point a,Point b){
    return abs(a-b);
}

double getDistanceLP(Line l,Point p){
    return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
    if(dot(s.p2-s.p1,p-s.p1)<0.0) return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2)<0.0) return abs(p-s.p2);
    return getDistanceLP(s,p);
}

double getDistance(Segment s1,Segment s2){
    if(intersect(s1,s2)) return 0.0;
    return min({getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2),getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)});
}

Point getCrossPointS(Segment s1,Segment s2){
    //if(ccw(s1.p1,s1.p2,s2.p1)==0&&ccw(s1.p1,s1.p2,s2.p2)==0) return s1.p1;
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}//

Point getCrossPointL(Line l1,Line l2){
    //if(ccw(s1.p1,s1.p2,s2.p1)==0&&ccw(s1.p1,s1.p2,s2.p2)==0) return s1.p1;
    
    Vector v1=l1.p2-l1.p1,v2=l2.p2-l2.p1;
    
    return l1.p1+v1*cross(v2,l2.p1-l1.p1)/cross(v2,v1);
}

Segment ParallelSegment(Segment s,double d){
    Vector v={-(s.p2-s.p1).y,(s.p2-s.p1).x};
    v=v/abs(v);
    
    s.p1=s.p1+v*d;
    s.p2=s.p2+v*d;
    
    return s;
}

Point naisin(Point p1,Point p2,Point p3){
    if(p1==p2&&p2==p3&&p3==p1) return p1;
    
    return (p1*abs(p2-p3)+p2*abs(p1-p3)+p3*abs(p1-p2))/(abs(p2-p3)+abs(p1-p3)+abs(p1-p2));
}

Point naisin(Line l1,Line l2,Line l3){
    //
    
    Point p1=getCrossPointL(l1,l2),p2=getCrossPointL(l1,l3),p3=getCrossPointL(l2,l3);
    return naisin(p1,p2,p3);
}

//

class Circle{
public:
    Point c;
    double r;
    Circle(Point c=Point(),double r=0.0):c(c),r(r){}
};

Point CircleCenter(Point a,Point b,Point c){
    Point u=a-b,v=a-c;
    double m1=(norm(a)-norm(b))/2.0,m2=(norm(a)-norm(c))/2.0;
    
    Point res;
    if(cross(u,v)==0.0){
        res.x=1e9;
        res.y=1e9;
        
        return res;
    }
    res.x=(m1*v.y-m2*u.y)/cross(u,v);
    res.y=(m1*v.x-m2*u.x)/cross(v,u);
    
    return res;
}
//3

// c1c2inside 0
// c1c2outside 1
//  2
//  3

int intersect(Circle c1,Circle c2){
    double d=getDistance(c1.c,c2.c);
    double r1=c1.r,r2=c2.r;
    if(r1<r2){
        if(d<(r2-r1)) return 0;
    }
    if(r1>r2){
        if(d<(r1-r2)) return 1;
    }
    if(d<=r1+r2) return 2;
    else return 3;
}

pair<Point,Point> segCrossPpoints(Circle c,Line l){
    //assert(intersect(c,l));
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    return make_pair(pr+e*base,pr-e*base);
}

double arg(Vector p){return atan2(p.y,p.x);}
Vector polar(double a,double r){return Point(cos(r)*a,sin(r)*a);}

//inside(outside)

pair<Point,Point> getCrossPoints(Circle c1,Circle c2){
    //assert(intersect(c1,c2));
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);
    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}

vector<Line> Commontangent(Circle c1,Circle c2){
    vector<Line> res;
    Point p=c2.c-c1.c;
    
    if(abs(p)>=(c1.r+c2.r)){
        Point a,b;
        a.x=c1.r*(p.x*(c1.r+c2.r)+p.y*sqrt(norm(p)-(c1.r+c2.r)*(c1.r+c2.r)))/norm(p);
        a.y=c1.r*(p.y*(c1.r+c2.r)-p.x*sqrt(norm(p)-(c1.r+c2.r)*(c1.r+c2.r)))/norm(p);
        
        b.x=c1.r*(p.x*(c1.r+c2.r)-p.y*sqrt(norm(p)-(c1.r+c2.r)*(c1.r+c2.r)))/norm(p);
        b.y=c1.r*(p.y*(c1.r+c2.r)+p.x*sqrt(norm(p)-(c1.r+c2.r)*(c1.r+c2.r)))/norm(p);
        
        res.push_back(Line{a+c1.c,a+c1.c+Point{-a.y,a.x}});
        if(!(a==b)){
            res.push_back(Line{b+c1.c,b+c1.c+Point{-b.y,b.x}});
        }
    }
    
    if(abs(p)>=abs(c1.r-c2.r)){
        Point a,b;
        a.x=c1.r*(p.x*(c1.r-c2.r)+p.y*sqrt(norm(p)-(c1.r-c2.r)*(c1.r-c2.r)))/norm(p);
        a.y=c1.r*(p.y*(c1.r-c2.r)-p.x*sqrt(norm(p)-(c1.r-c2.r)*(c1.r-c2.r)))/norm(p);
        
        b.x=c1.r*(p.x*(c1.r-c2.r)-p.y*sqrt(norm(p)-(c1.r-c2.r)*(c1.r-c2.r)))/norm(p);
        b.y=c1.r*(p.y*(c1.r-c2.r)+p.x*sqrt(norm(p)-(c1.r-c2.r)*(c1.r-c2.r)))/norm(p);
        
        res.push_back(Line{a+c1.c,a+c1.c+Point{-a.y,a.x}});
        if(!(a==b)){
            res.push_back(Line{b+c1.c,b+c1.c+Point{-b.y,b.x}});
        }
    }
    
    return res;
}

typedef vector<Point> Polygon;

/*
 IN 2
 ON 1
 OUT 0
 */

int contains(Polygon g,Point p){
    int n=int(g.size());
    bool x=false;
    for(int i=0;i<n;i++){
        Point a=g[i]-p,b=g[(i+1)%n]-p;
        if(a.y>b.y) swap(a,b);
        if(a.y<eps&&0<b.y&&cross(a,b)<0) x=!x;
        if(abs(cross(a,b))<eps&&dot(a,b)<eps) return 1;
    }
    return (x?2:0);
}

Polygon andrewScan(Polygon s,bool ok){
    Polygon u,l;
    sort(all(s));
    
    if(int(s.size())<3) return s;
    int n=int(s.size());
    
    u.push_back(s[0]);
    u.push_back(s[1]);
    
    l.push_back(s[n-1]);
    l.push_back(s[n-2]);
    
    if(ok){
        for(int i=2;i<n;i++){
            for(int j=int(u.size());j>=2&&ccw(u[j-2],u[j-1],s[i])==counter_clockwise;j--){
                u.pop_back();
            }
            u.push_back(s[i]);
        }
        
        for(int i=int(s.size())-3;i>=0;i--){
            for(int j=int(l.size());j>=2&&ccw(l[j-2],l[j-1],s[i])==counter_clockwise;j--){
                l.pop_back();
            }
            l.push_back(s[i]);
        }
    }
    
    if(!ok){
        for(int i=2;i<n;i++){
            for(int j=int(u.size());j>=2&&ccw(u[j-2],u[j-1],s[i])!=clockwise;j--){
                u.pop_back();
            }
            u.push_back(s[i]);
        }
        
        for(int i=int(s.size())-3;i>=0;i--){
            for(int j=int(l.size());j>=2&&ccw(l[j-2],l[j-1],s[i])!=clockwise;j--){
                l.pop_back();
            }
            l.push_back(s[i]);
        }
    }
    
    reverse(all(l));
    
    for(int i=int(u.size())-2;i>=1;i--) l.push_back(u[i]);
    
    return l;
}//ok==1

Polygon convex_cut(const Polygon& P, const Line& l) {
    Polygon Q;
    for(int i=0;i<si(P);i++){
        Point A=P[i],B=P[(i+1)%si(P)];
        if(ccw(l.p1,l.p2,A)!=-1)Q.push_back(A);
        if(ccw(l.p1,l.p2,A)*ccw(l.p1,l.p2,B)<0) Q.push_back(getCrossPointL(Line{A,B},l));
    }
    return Q;
}

double area(Point a,Point b,Point c){
    b=b-a;
    c=c-a;
    return abs(b.x*c.y-b.y*c.x)/2.0;
}

double area(Polygon &P){
    if(si(P)==0) return 0.0;
    double res=0;
    Point c={0.0,0.0};
    for(int i=0;i<si(P);i++){
        c=c+P[i];
    }
    c=c/si(P);
    
    for(int i=0;i<si(P);i++){
        res+=area(c,P[i],P[(i+1)%si(P)]);
    }
    
    return res;
}

//Union Find

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<Circle> C(N);
    for(int i=0;i<N;i++) cin>>C[i].c.x>>C[i].c.y>>C[i].r;
    
    int v=0,e=0,c=0;
    
    vector<Point> SE;
    UF uf;uf.init(N);
    
    for(int i=0;i<N;i++){
        vector<Point> X;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(intersect(C[i],C[j])==2){
                uf.unite(i,j);
                auto p=getCrossPoints(C[i],C[j]);
                X.push_back(p.fi);
                X.push_back(p.se);
            }
        }
        sort(all(X));
        X.erase(unique(all(X)),X.end());
        for(auto p:X) SE.push_back(p);
        e+=si(X);
    }
    
    sort(all(SE));
    SE.erase(unique(all(SE)),SE.end());
    
    v+=si(SE);
    for(int i=0;i<N;i++) if(uf.root(i)==i) c++;
    
    //cout<<v<<" "<<e<<" "<<c<<endl;
    
    cout<<e-v+c+1<<endl;
    
}