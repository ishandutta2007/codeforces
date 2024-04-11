#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,n;
int ask(int x)
{
    printf("?");
    for(int i=1;i<=k+1;i++)
    {
        if(i==x) continue;
        printf(" %d",i);
    }
    printf("\n");
    fflush(stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    return b;
}
void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}
vector<int> v;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k+1;i++) v.push_back(ask(i));
    sort(v.begin(),v.end());
    int cnt=1;
    for(int i=1;i<(int)v.size();i++)
    {
        if(v[i]==v[i-1]) cnt++;
        else break;
    }
    answer(k+1-cnt);
}