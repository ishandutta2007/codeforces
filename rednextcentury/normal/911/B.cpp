#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans=0;
    for (int i=1;i<=100;i++)
    {
        int x=1;
        while(a/x >= i) x++;
        x--;
        int y=1;
        while(b/y >= i) y++;
        y--;

        if (x>0 && y>0 && x+y>=n) ans=i;
    }
    cout<<ans<<endl;
}