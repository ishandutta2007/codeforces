/*
ID: Sfiction
OJ: CF
PROB: 380B
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=7000+10;
const int MAXR=200000;

int n;
int num[MAXN][4],len;
int left[MAXN],right[MAXN];

int add[MAXR];
int list[MAXN],lenl;

void Pre(){
    int i,j,k,x;
    x=1;
    i=1;
    j=2;
    for (;i<MAXR;++x){
        for (k=i;k<MAXR && k<j;++k)
            add[k]=x;
        i=j;
        j<<=1;
    }
}

int main(){
    int m;
    int com,t,l;
    int i;
    Pre();
    scanf("%d%d",&n,&m);
    len=0;
    for (;m;--m){
        scanf("%d%d%d",&com,&t,&l);
        if (com==1){
            num[len][0]=t;
            num[len][1]=l;
            scanf("%d%d",&num[len][2],&num[len][3]);
            ++len;
        }
        else{
            left[t]=right[t]=l;
            for (i=t+1;i<=n;++i){
                left[i]=add[left[i-1]-1]+left[i-1];
                right[i]=add[right[i-1]]+right[i-1];
            }
            lenl=0;
            for (i=0;i<len;++i)
                if (num[i][0]>=t){
                    if (num[i][1]>right[num[i][0]] || num[i][2]<left[num[i][0]])
                        continue;
                    list[lenl]=num[i][3];
                    ++lenl;
                }
            if (lenl){
                sort(list,list+lenl);
                int sum=1;
                for (i=1;i<lenl;++i)
                    if (list[i]!=list[i-1])
                        ++sum;
                printf("%d\n",sum);
            }
            else
                printf("0\n");
        }
    }
    return 0;
}