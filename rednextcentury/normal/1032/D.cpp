#include<bits/stdc++.h>
using namespace std;
#define ll long long
long double a,b,c;
long double getX(long double Y){
    return (-b*Y-c)/a;
}
long double getY(long double X){
    return (-a*X - c)/b;
}
long double dist(long double x1,long double y1,long double x2,long double y2){
    return hypot(x1-x2,y1-y2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long double x1,y1,x2,y2;
    cin>>a>>b>>c>>x1>>y1>>x2>>y2;
    long double ret=fabs(x1-x2)+fabs(y1-y2);
    ret = min(ret, fabs(x1-getX(y1))+fabs(y2-getY(x2))+dist(getX(y1),y1,x2,getY(x2)));
    ret = min(ret, fabs(y1-getY(x1))+fabs(y2-getY(x2))+dist(x1,getY(x1),x2,getY(x2)));
    ret = min(ret, fabs(x1-getX(y1))+fabs(x2-getX(y2))+dist(getX(y1),y1,getX(y2),y2));
    ret = min(ret, fabs(y1-getY(x1))+fabs(x2-getX(y2))+dist(x1,getY(x1),getX(y2),y2));
    cout<<setprecision(10)<<fixed<<ret<<endl;
}