#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int cnt[1111111];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,d;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&d,&k);
        int ret=1e9;
        int p=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            if (++cnt[a[i]]==1)p++;
            if (i-k>=1) if (--cnt[a[i-k]]==0)p--;
            if (i>=k) ret=min(ret,p);
        }
        for(int i=1;i<=n;i++)cnt[a[i]]=0;
        printf("%d\n",ret);
    }
}