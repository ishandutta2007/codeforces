#include<bits/stdc++.h>
using namespace std;
double h,l;
int main(){
    scanf("%lf%lf",&h,&l);
    printf("%.10lf",(l*l+h*h)/(2.0*h)-h);
    return 0;
}