#include <bits/stdc++.h>

using namespace std;
map<int,int> mpx;
map<int,int> mpy;
map<int,map<int,int> > mp1;
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans+=mpx[x]+mpy[y]-mp1[x][y];
        mpx[x]++;
        mpy[y]++;
        mp1[x][y]++;
    }
    cout<<ans<<endl;
}