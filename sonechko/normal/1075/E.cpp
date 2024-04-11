#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 11;

int a[N],b[N];
int c[N];
int ans;

int get(int l, int r, int k)
{
    return abs(a[l]-a[r])+abs(a[l]-a[k])+abs(a[r]-a[k])+
           abs(b[l]-b[r])+abs(b[l]-b[k])+abs(b[r]-b[k]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    c[1]=1;
    c[2]=1;
    c[3]=1;
    c[4]=1;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        if (a[i]<a[c[1]]) c[1]=i;
        if (a[i]>a[c[2]]) c[2]=i;
        if (b[i]<b[c[3]]) c[3]=i;
        if (b[i]>b[c[4]]) c[4]=i;
    }
    for (int i=1; i<=4; i++)
    for (int j=i+1; j<=4; j++)
    for (int l=1; l<=n; l++)
    if (l!=c[i]&&l!=c[j]) ans=max(ans,get(c[i],c[j],l));
    cout<<ans<<" ";
    for (int i=4; i<=n; i++)
        cout<<(a[c[2]]-a[c[1]]+b[c[4]]-b[c[3]])*2<<" ";
    cout<<endl;
}