#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline double sqr(double x){return x*x;}
inline double dis(double X1,double Y1,double X2,double Y2){return sqrt(sqr(X1-X2)+sqr(Y1-Y2));}
inline void cmax(double &x,double y){if(x<y)x=y;}
double X1,Y1,X2,Y2,X3,Y3,T1,T2;
double cc(double X1,double Y1,double X2,double Y2,double T,double Xp,double Yp)
{
    if(dis(X1,Y1,Xp,Yp)+dis(X2,Y2,Xp,Yp)-dis(X1,Y1,X2,Y2)<=T)
        return dis(X1,Y1,X2,Y2)+T-dis(X2,Y2,Xp,Yp);
    double L=0,R=1,M,X3,Y3;
    for(int k=300;k--;)
    {
        M=(L+R)/2;
        X3=X1*(1-M)+Xp*M,Y3=Y1*(1-M)+Yp*M;
        if(dis(X1,Y1,X3,Y3)+dis(X2,Y2,X3,Y3)-dis(X1,Y1,X2,Y2)<=T)
            L=M;
        else
            R=M;
    }
    return L*dis(X1,Y1,Xp,Yp);
}
double cc(double x,double y){return min(cc(X1,Y1,X2,Y2,T2,x,y),cc(X1,Y1,X3,Y3,T1,x,y));}
int main()
{
    
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&T1,&T2,&X1,&Y1,&X2,&Y2,&X3,&Y3);
    double r=0,L=0,R=1,M1,M2,Xp1,Yp1,Xp2,Yp2,v1,v2;
    cmax(r,max(cc(X2,Y2),cc(X3,Y3)));
    if(dis(X1,Y1,X3,Y3)+dis(X3,Y3,X2,Y2)-dis(X1,Y1,X2,Y2)<=T2)
        cmax(r,min(dis(X1,Y1,X2,Y2)+T2,dis(X1,Y1,X3,Y3)+dis(X3,Y3,X2,Y2)+T1));
    for(int k=300;k--;)
    {
        M1=(L*2+R)/3,M2=(L+R*2)/3;
        Xp1=X2*(1-M1)+X3*M1,Yp1=Y2*(1-M1)+Y3*M1;
        Xp2=X2*(1-M2)+X3*M2,Yp2=Y2*(1-M2)+Y3*M2;
        v1=cc(Xp1,Yp1),v2=cc(Xp2,Yp2);
        cmax(r,max(v1,v2));
        if(v1>v2)
            R=M2;
        else
            L=M1;
    }
    printf("%.18lf\n",r);
    return 0;
}