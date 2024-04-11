/*
ID: Sfiction
OJ: CF
PROB: 441B
*/
#include <cstdio>
#include <cstdlib>

const int MAXN=3000;

int n,v;
int fruit[MAXN][2];

int Comp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(){
    int day,last,sum;
    scanf("%d%d",&n,&v);
    for (int i=0;i<n;++i)
        scanf("%d%d",&fruit[i][0],&fruit[i][1]);
    qsort(fruit,n,sizeof(fruit[0]),Comp);
    day=1;
    last=v;
    sum=0;
    for (int i=0;i<n;){
        if (day>fruit[i][0]+1){
            ++i;
            continue;
        }
        while (day<fruit[i][0]){
            ++day;
            last=v;
        }
        if (fruit[i][1]>last){
            sum+=last;
            fruit[i][1]-=last;
            ++day;
            last=v;
        }
        else{
            sum+=fruit[i][1];
            last-=fruit[i][1];
            fruit[i][1]=0;
            ++i;
        }
    }
    printf("%d",sum);
    return 0;
}