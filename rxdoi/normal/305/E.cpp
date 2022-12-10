#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=5000+19;
int Sg[N],f[N],n;
char s[N];

int Calc(int L,int R)
{
    int tmp=0,res=0;
    for (int i=L+1;i<R;i++)
        if (s[i-1]==s[i+1]) tmp++;else res^=Sg[tmp],tmp=0;
    res^=Sg[tmp];
    return res;
}

int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    For(i,1,n+1)
    {
        for (int j=1;j<=i;j++) f[Sg[max(j-2,0)]^Sg[max(i-j-1,0)]]=i;
        while (f[Sg[i]]==i) Sg[i]++;
    }
    For(i,2,n)
        if (s[i-1]==s[i+1]&&(Calc(1,i-1)^Calc(i+1,n))==0) return printf("First\n%d\n",i),0;
    puts("Second");
}