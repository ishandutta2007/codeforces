/*
ID: Sfiction
OJ: CF
PROB: 468B
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=100000+10;

int n,sum[2];
int num[MAXN][3];

int Comp1(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int Comp2(const void *a,const void *b){
    return *((int *)a+1)-*((int *)b+1);
}

int Find(int key){
    int high=n,low=0;
    int mid;
    while (high-low>1){
        mid=(high+low)>>1;
        if (num[mid][0]>key)
            high=mid;
        else
            low=mid;
    }
    return num[low][0]==key ? low : -1;
}

int main(){
    scanf("%d%d%d",&n,&sum[0],&sum[1]);
    for (int i=0;i<n;++i){
        scanf("%d",&num[i][0]);
        num[i][1]=i;
        num[i][2]=0;
    }
    qsort(num,n,sizeof(num[0]),Comp1);

    for (int i=0;i<n;++i)
        if (num[i][2]==0){
            int j;
            int s1=0,s2=0;
            int flag,t,t1,t2;
            num[i][2]=-1;
            flag=0;
            for (j=num[i][0];(t1=Find(sum[flag]-j))>=0 && num[t1][2]==0;++s1){
                j=sum[flag]-j;
                num[t1][2]=-1;
                flag^=1;
            }
            flag=1;
            for (j=num[i][0];(t2=Find(sum[flag]-j))>=0 && num[t2][2]==0;++s2){
                j=sum[flag]-j;
                num[t2][2]=-1;
                flag^=1;
            }
            if ((s1+s2+1)&1){
                if (t1>=0){
                    --s1;
                    num[t1][2]=(num[t1][0]*2==sum[1])+1;
                }
                else
                    if (t2>=0){
                        --s2;
                        num[t2][2]=(num[t2][0]*2==sum[1])+1;
                    }
                    else{
                        printf("NO");
                        return 0;
                    }
            }
            int sign=s2&1;
            num[i][2]=sign+1;
            flag=0;
            for (j=num[i][0];(t=Find(sum[flag]-j))>=0 && num[t][2]==-1;flag^=1){
                j=sum[flag]-j;
                num[t][2]=sign+1;
            }
            flag=1;
            for (j=num[i][0];(t=Find(sum[flag]-j))>=0 && num[t][2]==-1;flag^=1){
                j=sum[flag]-j;
                num[t][2]=sign+1;
            }
        }
    qsort(num,n,sizeof(num[0]),Comp2);
    printf("YES\n");
    printf("%d",num[0][2]-1);
    for (int i=1;i<n;++i)
        printf(" %d",num[i][2]-1);
    return 0;
}