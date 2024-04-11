#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10],n,A[10],B[10];char s[100010];int S=-1,Sx,Sy,AS=-1,ASx,ASy,ASz;
void chk(int x,int y)
{
    memcpy(A,a,sizeof A),
    memcpy(B,a,sizeof B);
    A[x]--,B[y]--;
    if(A[x]<0||B[y]<0)return;
    int T=0;
    for(int i=0;i<10;i++)T+=min(A[i],B[9-i]);
    if(T>S)S=T,Sx=x,Sy=y;
}
int main()
{
    scanf("%s",s);n=strlen(s);
    for(int i=0;i<n;i++)a[s[i]-'0']++;
    for(int i=0;i<=a[0];i++)
    {
        a[0]-=i;S=-1,Sx=Sy=0;
        chk(1,9),chk(2,8),chk(3,7),chk(4,6),chk(5,5);a[0]+=i;
        if(S==-1)
        {
            if(i>=1&&i>=AS)AS=i,Sx=Sy=0,ASz=i-1;continue;
        }
        if(S+i+1>AS)AS=S+i+1,ASx=Sx,ASy=Sy,ASz=i;
    }
    if(AS<=0){printf("%s\n%s\n",s,s);return 0;}
    a[0]-=ASz;
    memcpy(A,a,sizeof A),
    memcpy(B,a,sizeof B);
    A[ASx]--,B[ASy]--;
    for(int i=0;i<10;i++)
        for(int j=0;j<A[i]-min(A[i],B[9-i]);j++)printf("%d",i);
    for(int i=0;i<10;i++)
        for(int j=0;j<min(A[i],B[9-i]);j++)printf("%d",i);
    printf("%d",ASx);
    for(int i=0;i<ASz;i++)putchar('0');
    puts("");
    for(int i=0;i<10;i++)
        for(int j=0;j<B[9-i]-min(A[i],B[9-i]);j++)printf("%d",9-i);
    for(int i=0;i<10;i++)
        for(int j=0;j<min(A[i],B[9-i]);j++)printf("%d",9-i);
    printf("%d",ASy);
    for(int i=0;i<ASz;i++)putchar('0');
    puts("");
    return 0;
}