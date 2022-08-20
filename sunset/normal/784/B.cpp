#include<bits/stdc++.h>
int s[]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int main(){
    int n,m=0;std::cin>>n;
    if(!n)m=1;
    while(n)m+=s[n%16],n/=16;
    std::cout<<m;
}