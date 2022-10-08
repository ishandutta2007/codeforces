#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define y1 gfdsgfdsg
struct pnt{
    double x,y;
    pnt(){
    }
    pnt(double xx,double yy){
        x=xx;
        y=yy;
    }
};
double vp(pnt a,pnt b){
    return a.x*b.y-a.y*b.x;
}
pnt v(pnt a,pnt b){
    return pnt(b.x-a.x,b.y-a.y);
}
double sp(pnt a,pnt b){
    return a.x*b.x+a.y*b.y;
}
double dst2(pnt a,pnt b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

pnt p[1000000];
double ss[1000000];
int fl[1000000];
int n;
double ans;
void obr(){
    ss[0]=0;
    for (int i=1;i<2*n;i++){
        ss[i]=ss[i-1]+vp(p[i-1],p[i])/2;
    }
    for (int i=0;i<n;i++){
        fl[i]=max(i+1,fl[i-1]);
        while (sp(v(p[i],p[i+1]),v(p[i+1],p[fl[i]]))<sp(v(p[i],p[i+1]),v(p[i+1],p[fl[i]+1])))
            fl[i]++;
        ans=min(ans,abs(sp(v(p[i],p[i+1]),v(p[i+1],p[fl[i]]))*
                        vp(v(p[i],p[i+1]),v(p[i+1],p[fl[i]])))/(2*dst2(p[i],p[i+1]))-
                abs(ss[fl[i]]-ss[i+1]+vp(p[fl[i]],p[i+1])/2));
    }
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[n+i]=p[i];
    }
    ans=1e100;
    obr();
    reverse(p,p+2*n);
    obr();
    printf("%.18lf\n",ans);
	return 0;
}