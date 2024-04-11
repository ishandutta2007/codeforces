#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
double a,b,c;
double x1,Y1,x2,y2;

typedef pair<double,double> pii;
vector<pii> v[2];
double dis(pii A,pii B){
    return sqrt((A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second));
}
int main() {
    scanf("%lf%lf%lf",&a,&b,&c);
    scanf("%lf%lf%lf%lf",&x1,&Y1,&x2,&y2);
    if(abs(a)<0.1 || abs(b)<0.1) {
        printf("%.8f\n", abs(x1-x2)+abs(Y1-y2)); return 0;
    }
    double ret = abs(x1-x2)+abs(Y1-y2);

    v[0].push_back(make_pair(x1,(1.0*c+1.0*a*x1)/(-b)));
    v[0].push_back(make_pair((1.0*b*Y1+c)/(-a),Y1));
    //printf("%.5f %.5f %.5f %.5f\n", v[0][0].first,v[0][0].second,v[0][1].first,v[0][1].second);
    v[1].push_back(make_pair(x2,(1.0*c+1.0*a*x2)/(-b)));
    v[1].push_back(make_pair((1.0*b*y2+c)/(-a),y2));

    ret = min(ret, abs(Y1-v[0][0].second) + dis(v[0][0],v[1][0]) + abs(y2-v[1][0].second));
    ret = min(ret, abs(Y1-v[0][0].second) + dis(v[0][0],v[1][1]) + abs(x2-v[1][1].first));
    ret = min(ret, abs(x1-v[0][1].first)  + dis(v[0][1],v[1][0]) + abs(y2-v[1][0].second));
    ret = min(ret, abs(x1-v[0][1].first)  + dis(v[0][1],v[1][1]) + abs(x2-v[1][1].first));
    printf("%.8f\n", ret);
}