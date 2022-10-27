#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1022;
const double EPS=1e-10;
int cnt[N];
set< pair<int,int> > bu[N], all;
LL add(LL a,LL b){
    return a+b;
}

struct P {
    LL x,y;
    //
    P(){}
    P(LL x,LL y):x(x),y(y){}

    //
    P operator + (P p) {
        return P(add(x,p.x),add(y,p.y));
    }
    //
    P operator - (P p) {
        return P(add(x,-p.x),add(y,-p.y));
    }

    //
    P operator * (LL d){
        return P(x*d,y*d);
    }

    //
    LL dot(P p){
        return add(x*p.x,y*p.y);
    }

    //
    LL det(P p){
        return add(x*p.y,-y*p.x);
    }
} p[N],q[N];

//qp1-p2
bool on_seg(P p1,P p2,P q)
{
    if(abs(q.x)>1e6 || abs(q.y)>1e6) return 0;
    return (p1-q).det(p2-q)==0 && (p1-q).dot(p2-q)<=0;
}
//p1-p2q1-q2(p1-q1).det(p2-q2)==0
LL gcd(LL x,LL y) {
    return y==0?x:gcd(y,x%y);
}
P intersection(P p1,P p2,P q1,P q2) {
    LL x = (q2-q1).det(q1-p1);
    LL y = (q2-q1).det(p2-p1); 
    LL g = gcd(abs(x), abs(y)); x /= g, y /= g;
    if ((p2-p1).x % y || (p2-p1).y % y) return P(1e9,1e9);
    return p1 + P((p2-p1).x / y * x, (p2-p1).y / y * x);
}
int n;
map< pair<LL,LL>, int > mp;
int main() {
    scanf("%d", &n);
    LL ans = 0;
    for(int i=1;i<=n;i++) {
        int x_1,x_2,y_1,y_2; 
        scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
        ans += gcd(abs(x_1-x_2),abs(y_1-y_2))+1;
        p[i] = P(x_1,y_1);
        q[i] = P(x_2,y_2);
    }
    for(int i=1;i<=n;i++) {
        if(p[i].x==q[i].x && p[i].y==q[i].y) continue;
        for(int j=i+1;j<=n;j++) {
            if((p[i]-q[i]).det(p[j]-q[j])==0) continue;
            P pnt = intersection(p[i],q[i],p[j],q[j]);
            if (on_seg(p[i],q[i],pnt) && on_seg(p[j],q[j],pnt)) {
                bu[i].insert(make_pair(pnt.x, pnt.y));
                bu[j].insert(make_pair(pnt.x, pnt.y));
                all.insert(make_pair(pnt.x, pnt.y));
            }
        }
    }
    for(int i=1;i<=n;i++) ans -= bu[i].size();
        ans += all.size();
    cout << ans << endl;
}