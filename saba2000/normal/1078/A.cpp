#include<bits/stdc++.h>
using namespace std;
double M(double x1, double y1, double x2, double y2){
    return fabs(x1-x2) + fabs(y1-y2);
}
double E(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double D(double x1, double y1, double x2, double y2,double x3, double y3, double x4, double y4){
    return M(x1,y1,x2,y2)+E(x2,y2,x3,y3)+M(x3,y3,x4,y4);
}
main(){

    int a, b, c;
    cin >> a>>b>>c;
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(a == 0 || b == 0){
        cout<<abs(x1-x2)+ abs(y1-y2) << endl;
        return 0;
    }
    //ax11+bY+c=0
    double x11 = x1, y11 = (-c-a*x11)/b, y12 = y1, x12 = (-c-b*y12)/a;
    double x21 = x2, y21 = (-c-a*x21)/b, y22 = y2, x22 = (-c-b*y22)/a;
    double ans = M(x1,y1,x2,y2);
    ans = min(ans, D(x1,y1,x11,y11,x21,y21,x2, y2));
    ans = min(ans, D(x1,y1,x12,y12,x21,y21,x2, y2));
    ans = min(ans, D(x1,y1,x11,y11,x22,y22,x2, y2));
    ans = min(ans, D(x1,y1,x12,y12,x22,y22,x2, y2));
    printf("%.9f", ans);

}
//