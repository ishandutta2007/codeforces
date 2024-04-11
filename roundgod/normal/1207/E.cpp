#include<bits/stdc++.h>
#define MAXN 300005
#define INF 100000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x,y;
int main()
{
    printf("?");
    for(int i=1;i<=100;i++) printf(" %d",i);
    printf("\n"); fflush(stdout);
    scanf("%d",&x);
    printf("?");
    for(int i=1;i<=100;i++)
    {
        int mask=0;
        for(int j=0;j<14;j++) if(i&(1<<j)) mask^=(1<<(13-j));
        printf(" %d",mask);
    }
    printf("\n"); fflush(stdout);
    scanf("%d",&y);
    int chosen=(x^y)&127;
    printf("! %d\n",x^chosen);
    fflush(stdout);
    return 0;
}