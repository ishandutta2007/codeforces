#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
vector<int> ans;
bool check(int x)
{
    int s=0,t=x;
    while(x>0)
    {
        s+=x%10;
        x=x/10;
    }
    return (t+s==n);
}
int main()
{
    scanf("%d",&n);
    for(int i=max(1,n-81);i<=n;i++)
        if(check(i)) ans.push_back(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
    return 0;
}