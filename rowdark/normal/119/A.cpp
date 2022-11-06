#include<iostream>
long a,b,n;
inline long gcd(long x,long y){
    register long z;
    while(z=x%y)x=y,y=z;
    return y;
}
inline long check(){
    while(1){
        if((n-=gcd(n,a))<0) return 1;
        if((n-=gcd(n,b))<0) return 0;
        }
}
int main(){
    std::cin>>a>>b>>n;
    std::cout<<check();return 0;
}