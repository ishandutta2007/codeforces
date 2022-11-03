/*
ID: Sfiction
OJ: CF
PROB: 469B
*/
#include <cstdio>

const int MAXN=50+10;

int p,q;
int x[MAXN][2],z[MAXN][2];

int main(){
    int l,r;
    int ans=0;

    scanf("%d%d",&p,&q);
    scanf("%d%d",&l,&r);
    for (int i=0;i<p;++i)
        scanf("%d%d",&z[i][0],&z[i][1]);
    for (int i=0;i<q;++i)
        scanf("%d%d",&x[i][0],&x[i][1]);
    x[q][0]=z[p][0]=1<<28;
    for (int i=l;i<=r;++i){
        int j,k;
        int last=-10,t;
        for (j=k=0;j<=q && k<=p;)
            if (x[j][0]+i<z[k][0]){
                if (last>=x[j][0]+i)
                    break;
                last=x[j++][1]+i;
            }
            else{
                if (last>=z[k][0])
                    break;
                last=z[k++][1];
            }
        if (j<=q && k<=p)
            ++ans;
    }
    printf("%d",ans);
    return 0;
}