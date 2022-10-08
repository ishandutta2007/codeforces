#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 100
int n,m,S=100;int a[50][800];
int main()
{
    scanf("%d%d",&n,&m);
    if(n<m)swap(n,m);
    int P=1;for(int i=0;i<m;i++)P*=3;
    for(int i=0;i<n;i++)
        for(int j=0;j<P;j++)a[i][j]=INF;
    if(n==1){puts("0");return 0;}
    for(int i=0;i<(1<<m);i++)
    {
        int S=0,p=0;
        for(int j=m-1;j>=0;j--)if((i>>j)&1)S++;
        for(int j=m-1;j>=0;j--)
            if((i>>j)&1)p*=3,p+=2;else
            if((j>0)&&((i>>(j-1))&1)||(j<m-1)&&((i>>(j+1))&1))p*=3,p+=1;
            else p*=3;
        a[0][p]=S;
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<P;j++)
        {
            if(a[i][j]==INF)continue;
            int b[50];
            for(int k=0,l=j;k<m;k++,l/=3)b[k]=l%3;
            for(int k=0;k<(1<<m);k++)
            {
                int S=0;
                for(int l=m-1;l>=0;l--)if((k>>l)&1)S++;
                bool F=1;
                for(int l=0;l<m;l++)
                    if(b[l]==0&&((k>>l)&1)==0){F=0;break;}
                if(!F)continue;
                int p=0;
                for(int l=m-1;l>=0;l--)
                    if((k>>l)&1)p*=3,p+=2;else
                    if((l>0)&&((k>>(l-1))&1)||(l<m-1)&&((k>>(l+1))&1)||b[l]==2)p*=3,p+=1;
                    else p*=3;
                a[i+1][p]=min(a[i+1][p],a[i][j]+S);
            }
        }
    for(int i=0;i<P;i++)
    {
        bool F=1;
        for(int j=0,k=i;j<m;j++,k/=3)
            if(k%3==0){F=0;break;}
        if(!F)continue;
        S=min(S,a[n-1][i]);
    }
    printf("%d\n",n*m-S);
    return 0;
}