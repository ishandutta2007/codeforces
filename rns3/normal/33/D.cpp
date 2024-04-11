#include<bits/stdc++.h>
using namespace std;
#define ep 1e-6
#define N 1111
bool vis[N][N];
double r[N];
struct pnt{
double x,y;
 pnt(double x=0,double y=0):x(x),y(y){}
 pnt operator-(pnt a){return pnt(x-a.x,y-a.y);}
 pnt operator+(pnt a){return pnt(x+a.x,y+a.y);}
 pnt operator*(double a){return pnt(x*a,y*a);}
 pnt operator/(double a){return pnt(x/a,y/a);}
double operator^(pnt a){return x*a.y-y*a.x;}
double operator&(pnt a){return x*a.x+y*a.y;}
void  input(){x=y=0, scanf("%lf %lf",&x,&y);}
void print(){printf("%lf %lf\n",x,y);}
}p[N], q[N];

double dist(pnt a) {
    return sqrt(a & a);
}
bool in(pnt a, double rr, pnt b) {
    double d = dist(a - b);
    if(rr + ep > d) return 1;
    return 0;
}
int main(){
    //freopen("D.in","r",stdin);
    int n, m, k;
    pnt A, B;
    int aa, bb;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i ++) p[i].input();
    for(int i = 0; i < m; i ++) scanf("%lf", &r[i]), q[i].input() ;
    for(int i = 0; i < n; i ++) {
         for(int j = 0; j < m; j ++) {
            if(in(q[j], r[j], p[i])) vis[i][j] = 1;
        }
    }

    for(int i = 0; i < k; i ++) {
        scanf("%d%d", &aa, &bb);
        int ans = 0;
        for(int j = 0; j < m; j++) {
            if(vis[aa-1][j] && vis[bb-1][j]) continue;
            if(!vis[aa-1][j] && !vis[bb-1][j]) continue;
            ans ++;
        }
        printf("%d\n", ans);
    }
}