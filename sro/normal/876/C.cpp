#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int weinum[]={2,11,101,1001,10001,100001,1000001,10000001,100000001,1000000001};
int p10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int num,n;
set<int> nums;

void dfs(int numnow,int wei,int msk)
{
	if(msk<0)return;
    if(numnow==0)nums.insert(msk);
    if(wei==-1)return;
    if(numnow/weinum[wei]==0)return dfs(numnow,wei-1,msk);
    int can=numnow/weinum[wei];
    if(can>10)return;
    dfs(numnow-weinum[wei]*(can-1),wei-1,p10[wei]*(can-1)+msk);
    if(can>=10)return;
    dfs(numnow-weinum[wei]*can,wei-1,p10[wei]*can+msk);
}

int main()
{
    scanf("%d",&n);
    dfs(n,9,0);
    printf("%d\n",nums.size());
    for(set<int>::iterator it=nums.begin();it!=nums.end();it++)
    	printf("%d ",*it);
    return 0;
}