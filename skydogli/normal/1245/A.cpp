#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        if(gcd(a,b)!=1){
            puts("Infinite");
        }
        else puts("Finite");
    }
}