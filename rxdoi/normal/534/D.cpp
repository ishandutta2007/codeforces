#include<cstdio>
#include<cctype>
#include<vector>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2e5+19;
int n,a,cnt,Ans[N];
vector<int> V[N];

int main()
{
    n=IN();
    For(i,0,n) a=IN(),V[a].push_back(i+1);
    For(i,0,n)
    {
        while (cnt>=0&&V[cnt].empty()) cnt-=3;
        if (cnt<0) return puts("Impossible"),0;
        Ans[i]=V[cnt].back();
        V[cnt++].pop_back();
    }
    puts("Possible");
    For(i,0,n) printf("%d ",Ans[i]);puts("");
}