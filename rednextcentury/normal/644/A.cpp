#include <bits/stdc++.h>
using namespace std;
int ret[101][101];
int cura=1;
int curb=2;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int x=1,y=2;
    int num[3];
    num[1]=n/2+n%2;
    num[2]=n/2;
    if (num[1]<num[2])
        swap(num[1],num[2]),swap(x,y);
    int cur=x;
    for (int i=0;i<a;i++)
    {
        if (i>0)
            cur=3-ret[i-1][0];
        for (int j=0;j<b;j++)
        {
            ret[i][j]=cur;
            cur=3-cur;
        }

    }
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            if (ret[i][j]==1 && num[1]==0)ret[i][j]=0;
            else if (ret[i][j]==2 && num[2]==0)ret[i][j]=0;
            else if (ret[i][j]==1)num[1]--,ret[i][j]=cura,cura+=2;
            else num[2]--,ret[i][j]=curb,curb+=2;
        }
    }
    if (num[1]!=0 || num[2]!=0)
        cout<<"-1"<<endl;
    else
    {
        for (int i=0;i<a;i++)
        {
            for (int j=0;j<b;j++)
                cout<<ret[i][j]<<" ";
            cout<<endl;
        }
    }
}