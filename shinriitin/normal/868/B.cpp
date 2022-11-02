#include <bits/stdc++.h>

int h,m,s,t1,t2;

double H,M,S,T1,T2;

const double pi=acos(-1.),eps=1e-9;

inline bool check(double x,double l,double r){
    if(r<l){
        return l-eps<x||x<r+eps;
    }
    else{
        return l-eps<x&&x<r+eps;
    }
}

inline bool check(double T1,double T2){
    if(check(H,T1,T2))return 0;
    if(check(M,T1,T2))return 0;
    if(check(S,T1,T2))return 0;
    return 1;
}

int main(){
    scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
    h%=12;
    S=1.*s*pi/30;
    M=1.*m*pi/30+pi/30*s/60;
    H=1.*h*pi/6+pi/6*(M/pi/2);
    T1=1.*t1*pi/6;
    T2=1.*t2*pi/6;
    if(check(T1,T2)||check(T2,T1))puts("YES");
    else puts("NO");
    return 0;
}