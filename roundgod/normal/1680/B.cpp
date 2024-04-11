#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
string str[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) cin>>str[i];
        int left=m-1,up=n-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='R')
                {
                    left=min(left,j);
                    up=min(up,i);
                }
            }
        bool f=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='R'&&left==j&&up==i) f=true;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}