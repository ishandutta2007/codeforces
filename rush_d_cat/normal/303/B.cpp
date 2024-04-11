#include <iostream>
using namespace std;
int n,m,x,y,a,b;
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main() {
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
    int g = gcd(a,b); a/=g, b/=g;
    int k = min(n/a,m/b); a*=k, b*=k;
    //printf("a = %d, b = %d\n", a, b);
    x*=2, y*=2;
    int x1=a,y1=b;
    int x2=2*n-a,y2=2*m-b;
    //printf("[%d, %d] %d\n", x1,x2,x);
    int cx; 
    if(x>x2) cx=x2; 
    else if(x<x1) cx=x1;
    else cx = x1 + (x - x1) / 2 * 2;
    
    //printf("[%d, %d] %d\n", y1,y2,y);
    int cy;
    if(y>y2) cy=y2;
    else if(y<y1) cy=y1;
    else cy = y1 + (y - y1) / 2 * 2;

    //printf("c(%d, %d)\n", cx, cy);

    int X1 = cx - a;
    int Y1 = cy - b;
    int X2 = cx + a;
    int Y2 = cy + b;
    printf("%d %d %d %d\n", X1/2,Y1/2,X2/2,Y2/2);
}