#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,block;
string str;
bool dead[MAXN];
int ask(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    cin>>str;
    if(str[0]=='Y') return 1; else return 0;
}
void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}
void reset()
{
    printf("R\n");
    fflush(stdout);
}
int main()
{
    scanf("%d%d",&n,&k);
    if(n==1&&k==1) answer(1);
    block=(k==1?1:k/2);
    memset(dead,false,sizeof(dead));
    int num=n/block;
    for(int i=1;i<=num/2;i++)
    {
        int st=i,delta=0;
        for(int j=1;j<=num;j++)
        {
            for(int k=(st-1)*block+1;k<=st*block;k++)
            {
                if(!dead[k])
                {
                    if(ask(k)) dead[k]=true;
                }
            }
            delta++;
            if(j&1) st-=delta; else st+=delta;
            if(st>num) st-=num;
            if(st<=0) st+=num;
        }
        reset();
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(!dead[i]) ans++;
    answer(ans);
    return 0;
}