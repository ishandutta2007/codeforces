#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int a[300001];
int ds;
int n;
int last[300001];
bool done[300001];
int sol[300001];
int par[300001];
bool can[300001];
int is[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)is[i]=0;
        for (int i=1;i<=n;i++){
            par[i]=0;
            scanf("%d",&a[i]);
            last[a[i]]=i,done[a[i]]=0,can[a[i]]=0;
            is[a[i]]=1;
        }
        int lst=0;
        ds=0;
        for (int i=1;i<=n;i++) {
            if (is[i]){
                par[i]=lst;
                ds++;
                lst=i;
            }
        }
        int ret=0;
        for (int i=1;i<=n;i++) {
            if (!done[a[i]]){
                int cur=1;
                if (a[i]>1)cur = (can[par[a[i]]]?sol[par[a[i]]]:0)+1;
                ret=max(ret,cur);
                sol[a[i]]=cur;
                done[a[i]]=1;
            }
            if (last[a[i]]==i) {
                can[a[i]]=1;
            }

        }
        printf("%d\n",ds-ret);
    }
}