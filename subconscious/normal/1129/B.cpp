#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
#define eb emplace_back
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
int a[N],k;
int main(){
    scanf("%d",&k);
    for(int c=2;c<=2000;++c){
        int bg=((k+1)/c+((k+1)%c!=0))*c;
        for(int tp=bg;tp<=k+1e6;tp+=c){
            int b=tp-k;
            if(tp/c<b){
                int a=b-tp/c;
                printf("%d\n",c);
                rep(i,c-2)printf("0 ");
                printf("%d %d\n",-a,b);
                return 0;
            }
        }
    }
    return 0;
}