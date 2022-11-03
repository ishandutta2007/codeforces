/*
ID: Sfiction
OJ: CF
PROB: 463D
*/
#include <cstdio>
#include <cstring>

const int MAXK=5,MAXN=1000+5;

int n;
int seq[MAXK][MAXN];
int sign[MAXK][MAXN];
int len[MAXN];

int main(){
    int k;
    int i,j,l;

    scanf("%d%d",&n,&k);
    for (i=0;i<k;++i)
        for (j=0;j<n;++j){
            scanf("%d",&seq[i][j]);
            sign[i][seq[i][j]]=j;;
        }

    int max=0;
    memset(len,0,sizeof(len));
    for (i=1;i<n;++i){
        int now=seq[0][i];
        for (j=0;j<i;++j)
            if (len[j]>=len[i]){
                int t=seq[0][j];
                for (l=1;l<k && sign[l][t]<sign[l][now];++l);
                if (l==k)
                    len[i]=len[j]+1;
            }
        if (max<len[i])
            max=len[i];
    }
    printf("%d",max+1);
    return 0;
}