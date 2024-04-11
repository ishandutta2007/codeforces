#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N=500000+10;
const int B=707;
typedef long long LL;
int q,a[N];
LL s[B+2][B+2];

int main(){
    scanf("%d",&q);
    while(q--) {
        int op,x,y; scanf("%d%d%d",&op,&x,&y);
        if(op==1) {
            int las=a[x];
            a[x]+=y;
            for(int i=1;i<B;i++){
                s[i][x%i] += y; 
            }
        }else{
            if(x>=B){
                LL ans=0;
                for(int i=y;i<=500000;i+=x) {
                    if(i>=1) ans+=a[i];
                }
                printf("%lld\n", ans);
            } else {
                printf("%lld\n", s[x][y]);
            }
        }
    }
}