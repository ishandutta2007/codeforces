#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

const int p=100;

int hl,hr,n,ans,sum,ec,flag,ff;
char ch;
double x;
int v[300],a[300],b[300],c[300],biao[300],hash[300],r[3000];

int main()
{
    scanf("%d %d %d",&hl,&hr,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %c %d %d",&v[i],&ch,&a[i],&b[i]);
        if (ch=='T') c[i]=100; else c[i]=0;
        biao[i]=i;
    }
    r[1]=hr;
    for (int i=2;i<=p;i++)
        if (i%2==0) r[i]=r[i-1]+(100-hr)*2; else r[i]=r[i-1]+hr*2;
    for (int i=1;i<=p;i++)
        r[i+p]=-r[i];
    sort(r+1,r+2*p+1);
    ans=0;
    for (int i=1;i<=2*p;i++)
    {
        memset(hash,0,sizeof(hash));
        flag=1;
        for (int j=-p*100;j<=p*100;j+=100)
        {
            ec=(j+p*100)%200;
            if (((j>=hl)&&(j<=r[i]))||((j<=hl)&&(j>=r[i])))
            {
                x=(double(100000)*(j-hl))/(r[i]-hl);
                //if (r[i]==-528) printf("%d %.10lf\n",j,x);
                ff=1;
                for (int k=1;k<=n;k++)
                    if (ec==c[k])
                        if ((x>=a[k])&&(x<=b[k]))
                        {
                            ++hash[k];ff=0;
                        }
                if (ff==1) {flag=0;break;}
            }
        }
        if (flag==0) continue;
        flag=1;
        for (int j=1;j<=n;j++)
            if (hash[j]>1)
            {
                flag=0;
                break;
            }
        if (flag==1)
        {
            sum=0;
            for (int j=1;j<=n;j++)
                if (hash[j]==1) sum+=v[j];
            ans=max(ans,sum);
        }
        //cout<<r[i]<<" "<<ans<<endl;
        //for (int j=1;j<=n;j++) cout<<hash[j];cout<<endl;
    }
    cout<<ans<<endl;

    return 0;
}