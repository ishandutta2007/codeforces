#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int l = -2000000000, r = 2000000000;
    string s;
    char c[5], y;
    int x;
    
    rep(i,n){
        scanf("%s%d %c",c,&x,&y);
        s = c;
        int t = 0;
        if(s == ">=") t = 0;
        if(s == "<") t = 1;
        if(s == "<=") t = 2;
        if(s == ">") t = 3;
        if(y == 'N') t ^= 1;
        switch(t){
            case 0:
                l = max(l,x);
                break;
            case 1:
                r = min(r,x-1);
                break;
            case 3:
                l = max(l,x+1);
                break;
            case 2:
                r = min(r,x);
                break;
        }
    }
    if(l > r) puts("Impossible");
    else printf("%d\n",l);
    
    return 0;
}