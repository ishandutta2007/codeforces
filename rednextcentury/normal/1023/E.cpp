#include<bits/stdc++.h>
using namespace std;
int n;
int can(int x,int y,int x2,int y2)
{
    if (x<=n && y<=n && x>0 && y>0)
    {
        if (x2<=n && y2<=n && x2>0 && y2>0)
        {
            if ((x2-x+y2-y)>=n-1)
            {
                cout<<'?'<<' '<<x<<' '<<y<<' '<<x2<<' '<<y2<<endl;
                fflush(stdout);
                string ret;
                cin>>ret;
                if (ret=="YES")return 1;
                else return 0;
            }
        }
    }
    return 0;
}
int main()
{
    cin>>n;
    int x=1,y=1;
    string ret="";
    while(1)
    {
        int X=x+1;
        int Y=y;
        if (can(X,Y,n,n))
        {
            ret+="D";
            x=X;
            y=Y;
            continue;
        }
        X=x;
        Y=y+1;
        if (can(X,Y,n,n))
        {
            ret+="R";
            x=X;
            y=Y;
            continue;
        }
        break;
    }
    string ret2="";
    int sx=x,sy=y;
    x=n,y=n;
    while(1)
    {
        if (x==sx && y==sy)
        {
            break;
        }
        int X=x;
        int Y=y-1;
        if (can(1,1,X,Y))
        {
            ret2+="R";
            x=X;
            y=Y;
            continue;
        }
        X=x-1;
        Y=y;
        if (can(1,1,X,Y))
        {
            ret2+="D";
            x=X;
            y=Y;
            continue;
        }
        break;
    }
    reverse(ret2.begin(),ret2.end());
    ret=ret+ret2;
    cout<<"! "<<ret<<endl;
}