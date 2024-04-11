#include <bits/stdc++.h>
using namespace std;
int A[100],len[100000];
int id,h,w,st,mv;
char ret[1000][1000];
int num=0;
void Set(int y,int x,int dx)
{
    if (y<0)return;
    if ( x==-1 || x==len[y] || x==w)
    {
        Set(y-1,x-dx,-dx);
        return;
    }
    if (num==A[id])id++,num=0;
    ret[y][x]=char(id+'a');
    num++;
    Set(y,x+dx,dx);
}
int main()
{
    int a,b,c,d,n;
    cin>>a>>b>>c>>d>>n;
    for (int i=0;i<n;i++)
        cin>>A[i];
    if (b>d)
    {
        id=0,h=b,w=a+c,st,mv;
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++)
                ret[i][j]='.';
        for (int i=0;i<d;i++)
            len[i]=a+c;
        for (int i=d;i<b;i++)
            len[i]=a;
        if ((b-d)%2==0)
            Set(b-1,0,1);
        else
            Set(b-1,len[b-1]-1,-1);
    }
    else
    {
        id=0,h=d,w=a+c,st,mv;
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++)
                ret[i][j]='.';
        for (int i=0;i<b;i++)
            len[i]=-1;
        for (int i=b;i<d;i++)
            len[i]=a-1;
        if ((d-b)%2==0)
            Set(d-1,a+c-1,-1);
        else
            Set(d-1,a,1);
    }
    cout<<"YES"<<endl;
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            cout<<ret[i][j];
        }
        cout<<'\n';
    }
}