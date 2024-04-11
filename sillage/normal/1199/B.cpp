#include<cstdio>
int h,l;
int main(){
    scanf("%d%d",&h,&l);
    printf("%.10lf\n",(1.0*l*l-1.0*h*h)/h/2);
}