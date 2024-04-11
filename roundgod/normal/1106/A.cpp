#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans=0;
string str[MAXN];
bool check(int x,int y)
{
    if(str[x][y]!='X') return false;
    if(x==0||y==0||x==n-1||y==n-1) return false;
    if(str[x-1][y-1]!='X'||str[x-1][y+1]!='X'||str[x+1][y-1]!='X'||str[x+1][y+1]!='X') return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>str[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(check(i,j)) ans++;
    printf("%d\n",ans);
    return 0;
}