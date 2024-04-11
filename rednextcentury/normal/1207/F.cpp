#include <bits/stdc++.h>
using namespace std;
int SQ;
int ret[500][500];
int a[1000000];
int main()
{
    srand(time(NULL));
    SQ = rand()%60+330;
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++)
    {
        int typ;
        scanf("%d",&typ);
        if (typ==1){
            int x,y;
            scanf("%d%d",&x,&y);
            for (int j=1;j<=SQ;j++)
                ret[j][x%j]+=y;
            a[x]+=y;
        } else {
            int mod,y;
            scanf("%d%d",&mod,&y);
            if (mod<=SQ)
                printf("%d\n",ret[mod][y]);
            else
            {
                int cur = y;
                int ans=0;
                while(cur<=500000)
                {
                    ans+=a[cur];
                    cur+=mod;
                }
                printf("%d\n",ans);
            }
        }
    }

}