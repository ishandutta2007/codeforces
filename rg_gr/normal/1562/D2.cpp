#include <bits/stdc++.h>

using namespace std;
const int N=3e5+10;
int sum[N];
char s[N];
vector<int>v[2][N*2];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<=n*2+1;i++){
            v[1][i].clear();
            v[0][i].clear();
        }
        sum[0]=n+1;
        scanf("%s",s+1);
        for(int i=1; i<=n; i++)
        {
            sum[i]=sum[i-1]+((i&1)?1:-1)*(s[i]=='+'?1:-1);
            if(i&1)v[s[i]=='+'?1:0][sum[i]].push_back(i);
            else v[s[i]=='+'?0:1][sum[i]].push_back(i);
        }
        while(q--)
        {
            int l,r;
            int d;
            scanf("%d%d",&l,&r);
        //    cout<<l<<' '<<r<<endl;
            if(sum[r]==sum[l-1]){
                    printf("0\n");
                    continue;
            }
            else if((r-l+1)&1)
            {
                printf("1\n");
                d=sum[r]-sum[l-1];
            }
            else
            {
                printf("2\n");
                printf("%d ",r);
                d=sum[r-1]-sum[l-1];
            }
            int sum1=(d+1)/2+sum[l-1];
    //        continue;
            if(d<0)
            {
                d=-d;
                sum1=sum[l-1]-(d+1)/2;
                printf("%d",v[0][sum1][lower_bound(v[0][sum1].begin(),v[0][sum1].end(),l)-v[0][sum1].begin()]);
            }
            else printf("%d",v[1][sum1][lower_bound(v[1][sum1].begin(),v[1][sum1].end(),l)-v[1][sum1].begin()]);
//            printf("%d",*lower_bound(v[1][sum1].begin(),v[1][sum1].end(),l));
            puts("");
        }
    }
    return 0;
}