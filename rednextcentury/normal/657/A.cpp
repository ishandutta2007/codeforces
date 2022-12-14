#include<bits/stdc++.h>
using namespace std;
int res[1000000][2];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,d,h;
    cin>>n>>d>>h;
    if (h>d || (h==d && n>h+1 && h==1) || d>2*h)
    {
        cout<<-1<<endl;
        return 0;
    }
    int v=h+2;
    for (int i=2;i<=h+1;i++)
    {
        cout<<i-1<<" "<<i<<endl;
    }
    int last=1;
    for (int i=0;i<d-h;i++)
    {
        cout<<v<<" "<<last<<endl;
        last=v;
        v++;
    }
    for (;v<=n;v++)
        cout<<v<<" "<<h<<endl;
}