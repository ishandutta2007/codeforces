#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e5 + 11;
const ll MOD = 1e18;
#define mod %MOD
int a[N],b[N],use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int kol=0;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        if (a[i]!=b[i]) kol++;
    }
    int x1=0,y1=0,x2=0,y2=0;
    for (int i=1; i<=n; i++)
        if (a[i]==b[i]) use[a[i]]++; else
        {
            if (x1==0) {x1=a[i]; y1=b[i];} else
                {
                    x2=a[i];
                    y2=b[i];
                }
        }
    if (kol==2)
    {
        int d1,d2;
        if (use[x1]==0&&use[y2]==0&&x1!=y2) {d1=x1; d2=y2;}
        if (use[x1]==0&&use[x2]==0&&x1!=x2) {d1=x1; d2=x2;}
        if (use[y1]==0&&use[x2]==0&&y1!=x2) {d1=y1; d2=x2;}
        if (use[y1]==0&&use[y2]==0&&y1!=y2) {d1=y1; d2=y2;}
        for (int i=1; i<=n; i++)
        if (a[i]==b[i]) cout<<a[i]<<" "; else
        if (a[i]!=b[i])
        {
            kol--;
            if (kol==1) cout<<d1<<" "; else cout<<d2<<" ";
        }
        return 0;
    }
    if (kol==0)
    {
        for (int i=1; i<=n; i++)
            if (use[a[i]]>1)
        {
            int p=0;
            for (int j=1; j<=n; j++)
                if (use[j]==0) p=j;
            use[a[i]]--;
            cout<<p<<" ";
        } else cout<<a[i]<<" ";
        return 0;
    }
    for (int i=1; i<=n; i++)
        if (a[i]!=b[i])
    {
        for (int j=1; j<=n; j++)
            if (use[j]==0) {cout<<j<<" "; break;}
    } else cout<<a[i]<<" ";
}