#include<iostream>
#define O std::cin
int t,x,o,p;int main(){O>>t;while(O>>p){o=t=0;while(p--)O>>x,o+=x&1,t++;puts(o%2+o%t?"YES":"NO");}}