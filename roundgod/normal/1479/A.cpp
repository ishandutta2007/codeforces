#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int query(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    int y;
    scanf("%d",&y);
    return y;
}
void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    int l=0,r=n+1;
    while(r-l>2)
    {
        int mid=(l+r)/2;
        if(query(mid)<query(mid+1)) r=mid+1; else l=mid;
    }
    answer(l+1);
    return 0;
}