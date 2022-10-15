#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,a,b;
int cnt1,cnt2;
int main()
{
    scanf("%d",&n);
    cnt1=cnt2=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a>0) cnt1++; else cnt2++;
    }
    if(cnt1==1||cnt2==1||cnt1==0||cnt2==0) puts("Yes"); else puts("No");
    return 0;
}