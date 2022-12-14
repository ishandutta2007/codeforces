#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
multiset<int> s;
int dp[100010];
int lch[400010],rch[400010],num[400010];
void insert(int i,int l,int r,int j,int k)
{
    if(l==r)
    {
        num[i]=k;
        return;
    }
    int mid=(l+r)>>1;
    if(j>mid)
        insert(i*2+1,mid+1,r,j,k);
    else
        insert(i*2,l,mid,j,k);
    num[i]=min(num[i*2],num[i*2+1]);
}
int get(int i,int l,int r,int x,int y)
{
    if(l==x&&r==y)
        return num[i];
    int mid=(l+r)>>1;
    if(x>mid)
        return get(i*2+1,mid+1,r,x,y);
    else
        if(y<=mid)
            return get(i*2,l,mid,x,y);
        else
            return min(get(i*2,l,mid,x,mid),get(i*2+1,mid+1,r,mid+1,y));
}
int dig[100010];
multiset<int>::iterator it;
int main()
{
    dp[0]=0;
    int now=1,n,z,l,n1;
    cin>>n>>z>>l;
    for(n1=1;n1<=n;n1++)
        scanf("%d",&dig[n1]);
    insert(1,1,n+1,1,0);
    for(n1=1;n1<=n;n1++)
    {
        s.insert(dig[n1]);
        it=s.end();
        it--;
        int mx=*it;
        int mn=*s.begin();
        while(mx-mn>z)
        {
            s.erase(s.find(dig[now]));
            it=s.end();
            it--;
            mx=*it;
            mn=*s.begin();
            now++;
        }
        if(n1-now+1<l)
        {
            dp[n1]=inf;
            insert(1,1,n+1,n1+1,dp[n1]);
            continue;
        }
        dp[n1]=get(1,1,n+1,now,n1-l+1)+1;
        insert(1,1,n+1,n1+1,dp[n1]);
    }
    if(dp[n]>n)
        printf("-1\n");
    else
        printf("%d\n",dp[n]);
}