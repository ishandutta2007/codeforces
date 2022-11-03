/*
ID: Sfiction
OJ: CF
PROB: 202B
*/
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXL=10+2;

char lesha[4][MAXL];
int p[4];
char ivan[21][MAXL];

int main(){
    int n,m;
    int inverse=100,num=0;

    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%s",lesha[i]);
        p[i]=i;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;++i){
        int len;
        scanf("%d",&len);
        for (int j=0;j<len;++j)
            scanf("%s",ivan[j]);

        int inv=0;
        for (int j=0;j<n;++j)
            p[j]=j;
        while (1){
            int j,k;

            for (j=0,k=0;j<len && k<n;++j)
                if (!strcmp(ivan[j],lesha[p[k]]))
                    ++k;
            if (k==n && inverse>inv){
                inverse=inv;
                num=i;
            }

            for (j=n-1;j>0 && p[j]<p[j-1];--j);
            if (j==0)
                break;
            inv-=(n-j)*(n-j-1)/2-1;
            int min=j--;
            for (k=min+1;k<n;++k)
                if (p[j]<p[k] && p[k]<p[min])
                    min=k;
            swap(p[j],p[min]);
            for (k=(n+j)>>1;k>j;--k)
                swap(p[k],p[n+j-k]);
        }
    }

    if (num){
        int p=n*(n-1)/2+1-inverse;
        printf("%d\n[:",num);
        for (int i=0;i<p;++i)
            putchar('|');
        printf(":]");
    }
    else
        printf("Brand new problem!");
    return 0;
}