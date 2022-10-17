#include<iostream>
long long a[1<<20],i=1,j,k,o=1,q,t;
char c;
int main(){
    for(std::cin>>k;std::cin>>c;a[o]=++i)
        if(c-48)
            a[o++]=i;
    
    for(i=k;i<o;)t+=(a[i+1]-a[i++])*(a[j+1]-a[j++]-!k)/(1+!k);
    std::cout<<t<<"\n";
}