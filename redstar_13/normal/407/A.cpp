#include<bits/stdC++.h>
using namespace std;
typedef long long INT;
#define st(x) ((x)*(x))
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int a,b,flag=1,i;
    cin>>a>>b;
    for(i=-1;i>-a+1;i--){
        int y=sqrt(st(a)-st(i));
        if(st(y)+st(i)==st(a)){
            if(st(-i*b/a)+st(b*y/a)==b*b and y!=-i*b/a){
                flag=0;
                puts("YES");
                printf("0 0\n%d %d\n%d %d\n",i,y,b*y/a,(-i)*b/a); 
                break;    
            }
        }
    }
    if(flag)puts("NO");
    return 0;
}