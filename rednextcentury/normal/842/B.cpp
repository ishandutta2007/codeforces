#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R,D;
    cin>>R>>D;
    R=R-D;
    int n;
    cin>>n;
    int num=0;
    for (int i=0;i<n;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        int d1=x*x+y*y;
        if (d1<(R+r)*(R+r))continue;
        if (d1>(R+D-r)*(R+D-r))continue;
        num++;
    }
    cout<<num<<endl;
}