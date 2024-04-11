#include <bits/stdc++.h>
using namespace std;
int U[1000000];
int D[1000000];
int L[1000000];
int R[1000000];
int X,Y;
int gX,gY;
int n;
bool check(int mid)
{
    for (int i=mid-1;i<n;i++)
    {
        int x = X, y=Y;
        x-=R[i];x+=L[i];
        y-=U[i];y+=D[i];
        if (i>=mid)
            x+=R[i-mid],x-=L[i-mid],y+=U[i-mid],y-=D[i-mid];
        int need = abs(x-gX)+abs(y-gY);
        if (need<=mid && (mid-need)%2==0)
            return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>n;
    cin>>s;
    int x,y;
    cin>>x>>y;
    gX=x,gY=y;
    for (int i=0;i<n;i++)
    {
        U[i]=U[i-1];
        D[i]=D[i-1];
        R[i]=R[i-1];
        L[i]=L[i-1];
        if (s[i]=='U')U[i]++,Y++;
        if (s[i]=='D')D[i]++,Y--;
        if (s[i]=='L')L[i]++,X--;
        if (s[i]=='R')R[i]++,X++;
    }
    if (abs(x)+abs(y)>n)
    {
        cout<<-1<<endl;
        return 0;
    }
    if ((n-(abs(x)+abs(y)))%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (x==X && y==Y)
    {
        cout<<0<<endl;
        return 0;
    }
    int ret=n;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            ret=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ret<<endl;
}