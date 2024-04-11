#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=200000+10;
int T,n,ans[N];
struct Nod{
    int l,r,id;
    bool operator<(const Nod&o)const{
        return l<o.l;
    } 
} nod[N];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&nod[i].l,&nod[i].r); nod[i].id=i;
        }
        sort(nod+1,nod+1+n);
        
        int mx=nod[1].r;
        int pos=-1;
        for(int i=1;i<=n;i++){
            if(nod[i].l > mx) {
                pos=nod[i].l; break;
            } else {
                mx = max(mx,nod[i].r);
            }
        }
        if(pos==-1) {
            printf("-1\n");
            continue;
        }else{
            for(int i=1;i<=n;i++)
                if(nod[i].l >= pos) ans[nod[i].id]=2;
                else ans[nod[i].id]=1;
        }
        for(int i=1;i<=n;i++) printf("%d ", ans[i]);
        printf("\n");
    }
}