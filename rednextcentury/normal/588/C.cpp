# include<iostream>
# include<algorithm>
# include<string>
# include<cstring>
# include<stdio.h>
# include<cmath>
# include<iomanip>
# include<map>
# include<cstdlib>
# include<vector>
# include<set>
# include<queue>
# include<assert.h>
using namespace std;
int num[10000000];
int main()
{
    int n;
    scanf("%d",&n);
    int mx=0;
    for (int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        num[a]++;
        mx=max(mx,a);
    }
    int carry=0;
    int i=0;
    int ans=0;
    while(carry || i<mx+1)
    {
        num[i]+=carry;
        carry=num[i]/2;
        num[i]=num[i]%2;
        if (num[i])
            ans++;
        i++;
        assert(i<10000000);
    }
    printf("%d\n",ans);
}