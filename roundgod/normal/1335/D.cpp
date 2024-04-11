#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
char mp[15][15];
bool valid[10];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<9;i++) scanf("%s",mp[i]);
        int tot=0,j=0;
        for(int i=0;i<9;i++)
        {
            if(i%3==0)
            {
                j=tot;
                tot++;
            }
            else j+=3;
            if(mp[i][j]=='1') mp[i][j]='2'; else mp[i][j]='1';
        }
        for(int i=0;i<9;i++) printf("%s\n",mp[i]);
    }
    return 0;
}