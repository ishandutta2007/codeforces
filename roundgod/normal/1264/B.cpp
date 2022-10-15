#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[4],b[4];
vector<int> ans;
void tryleft(int cur)
{
    if(!a[cur]) return;
    ans.clear();
    for(int i=0;i<4;i++) b[i]=a[i];
    int now=cur,cnt=0;
    do
    {
        b[now]--; cnt++;
        ans.push_back(now);
        if(now-1>=0&&b[now-1]) now--;
        else if(now+1<4&&b[now+1]) now++;
        else break;
    }while(true);
    if(cnt==n)
    {
        puts("YES");
        for(auto x:ans) printf("%d ",x);
        exit(0);
    }
}
void tryright(int cur)
{
    if(!a[cur]) return;
    ans.clear();
    for(int i=0;i<4;i++) b[i]=a[i];
    int now=cur,cnt=0;
    while(!a[now]) now--;
    do
    {
        b[now]--; cnt++;
        ans.push_back(now);
        if(now+1<4&&b[now+1]) now++;
        else if(now-1>=0&&b[now-1]) now--;
        else break;
    }while(true);
    if(cnt==n)
    {
        puts("YES");
        for(auto x:ans) printf("%d ",x);
        exit(0);
    }
}
int main()
{
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    n=a[0]+a[1]+a[2]+a[3];
    for(int i=0;i<4;i++) tryleft(i),tryright(i);
    puts("NO");
    return 0;
}