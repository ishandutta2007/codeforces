#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
void swp(ll &a,ll &b){
    ll t=a;
    a=b;
    b=t;
}
bool check(ll x){
    if(!(x&1)){
        return 0;
    }
    for(ll i=3;i*i<=x;i+=2){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int t;
    ll a,b;
    scanf("%d",&t);
    while(t--){
        cin>>a>>b;
        if(a<b){
            swp(a,b);
        }
        if((a+b)!=1&&(a-b)!=1){
            puts("NO");
        }
        else{
            if(a-b==1){
                if(check(a+b)){
                    puts("YES");
                }
                else{
                    puts("NO");
                }
            }
            else{
                if(check(a-b)){
                    puts("YES");
                }
                else{
                    puts("NO");
                }
            }
        }
    }
    return 0;
}