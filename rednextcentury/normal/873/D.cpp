#include<bits/stdc++.h>
using namespace std;
int a[1000000];
bool ok=0;
int num=0;
int k;
void solve(int l,int r,int x,int y)
{
    if (l+1==r || num==k)
    {
        for (int i=l;i<r;i++)
            a[i]=x+i-l;
        return;
    }
    else
    {
        num+=2;
        solve(l,(l+r)/2,(x+y)/2+1,y);
        solve((l+r)/2,r,x,(x+y)/2);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n>>k;
    if (k%2==0)cout<<-1<<endl;
    else
    {
        num=1;
        solve(0,n,1,n);
        if (num==k)
        {
            for (int i=0;i<n;i++)
                cout<<a[i]<<' ';
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}