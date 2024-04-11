#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[1000000];
int main(){
    ios_base::sync_with_stdio(0);
    long long n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i],a[i]+=ta;
    for (int i=1;i<=m;i++)
        cin>>b[i];
    int num=-1;
    a[n+1]=1e9+2;
    int r=1;
    long long ret=-1;
    for (int l=0;l<=n;l++)
    {
        long long cur = a[l+1];
        num++;
        if (num>k)break;
        while(r<=m && b[r]<cur)r++;
        int left = k-num;
        long long cur2 = b[r+left];
        if (cur>cur2)
            ret=1e18;
        else
            ret=max(ret,cur2+tb);
    }
    if (ret>1e17)ret=-1;
    cout<<ret<<endl;
}