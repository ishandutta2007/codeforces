#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    scanf("%d",&x);
    return x;
}

int main(){
    int a=ask(1,1),b=ask(1,inf);
    int x=(1+inf)/2;
    if(a!=b){
        if(a>b) x=(a-b+inf+1)/2;
        else x=(inf-b+a+1)/2;
    }
    int h=ask(1,x)+1;
    int c=ask(h,1)+1;
    int d=ask(h,inf);
    int e=ask(inf,c);
    printf("! %d %d %d %d\n",h,c,(int)inf-e,(int)inf-d);
    return 0;
}