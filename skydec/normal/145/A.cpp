#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
char A[MAXN],B[MAXN];
int n;
int main()
{
    scanf("%s",A+1);
    scanf("%s",B+1);
    n=strlen(A+1);
    int dif4=0;
    int dif7=0;
    for(int i=1;i<=n;i++)
    if(A[i]=='4'&&B[i]=='7')dif4++;
    else if(A[i]=='7'&&B[i]=='4')dif7++;
    int ans=dif4;
    if(ans<dif7)ans=dif7;
    printf("%d\n",ans);
    return 0;
}