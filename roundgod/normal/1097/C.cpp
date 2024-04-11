#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str[MAXN];
int cc[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>str[i];
    for(int i=0;i<n;i++)
    {
        int cnt=0,minx=0;
        for(int j=0;j<(int)str[i].size();j++) 
        {
            if(str[i][j]=='(') cnt++; else cnt--;
            minx=min(minx,cnt);
        }
        if(cnt>=0&&minx>=0) cc[cnt+500000]++;
        else if(cnt<0&&minx>=cnt) cc[cnt+500000]++;
    }
    int ans=0;
    ans+=cc[500000]/2;
    for(int i=500001;i<=1000000;i++) ans+=min(cc[i],cc[1000000-i]);
    printf("%d\n",ans);
    return 0;
}