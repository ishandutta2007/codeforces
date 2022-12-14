#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[2001][2001];
char b[2001][2001];
int r[2001];
int c[2001];
bool check()
{
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i][j]=='W')
                return 0;
    return 1;
}
void Fill(int x1,int y1,int x2,int y2)
{
    for (int j=y1;j<=y2;j++)
    {
        if (a[x1][j]=='W')
            a[x1][j]='w';
        if (a[x1][j]=='.')
            a[x1][j]='+';
        if (a[x2][j]=='W')
            a[x2][j]='w';
        if (a[x2][j]=='.')
            a[x2][j]='+';
    }
    for (int i=x1;i<=x2;i++)
    {
        if (a[i][y1]=='W')
            a[i][y1]='w';
        if (a[i][y1]=='.')
            a[i][y1]='+';
        if (a[i][y2]=='W')
            a[i][y2]='w';
        if (a[i][y2]=='.')
            a[i][y2]='+';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> X,Y;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='w')
            {
                X.insert(i);
                Y.insert(j);
                r[i]++,c[j]++;
                a[i][j]='W';
            }
        }
    }
    if (X.size()==1 && Y.size()==1)
        a[*X.begin()][*Y.begin()]='w';
    else if (X.size()==1 && Y.size()>1)
    {
        int x = *X.begin();
        int l = *Y.begin();
        int r = *(--Y.end());
        int w = r-l+1;
        if (x+1 >= w)
            Fill(x+1-w,l,x,r);
        else if (n-x >= w)
            Fill(x,l,x+w-1,r);
        else if (n>=w)
            Fill(0,l,w-1,r);
        else
            return cout<<-1<<endl, 0;
    }
    else if (X.size()>1 && Y.size()==1)
    {
        int y = *Y.begin();
        int l = *X.begin();
        int r = *(--X.end());
        int w = r-l+1;
        if (y+1 >= w)
            Fill(l,y+1-w,r,y);
        else if (m-y >= w)
            Fill(l,y,r,y+w-1);
        else if (m>=w)
            Fill(l,0,r,w-1);
        else
            return cout<<-1<<endl, 0;
    }
    else
    {
        int x1 = *X.begin() , x2 = *(--X.end());
        int y1 = *Y.begin() , y2 = *(--Y.end());
        int w = y2-y1+1;
        int h = x2-x1+1;
        if (w==h)
            Fill(x1,y1,x2,y2);
        else if (w>h)
        {
            if (x2>=w-1)
            {
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        b[i][j]=a[i][j];
                Fill(x2-w+1,y1,x2,y2);
                if (check())
                {
                    for (int i=0;i<n;i++)
                    {
                        for (int j=0;j<m;j++)
                            cout<<a[i][j];
                        cout<<endl;
                    }
                    return 0;
                }
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        a[i][j]=b[i][j];
            }
            if (n-x1>=w)
            {
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        b[i][j]=a[i][j];
                Fill(x1,y1,x1+w-1,y2);
                if (check())
                {
                    for (int i=0;i<n;i++)
                    {
                        for (int j=0;j<m;j++)
                            cout<<a[i][j];
                        cout<<endl;
                    }
                    return 0;
                }
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        a[i][j]=b[i][j];
            }
            if (n>=w)
            {
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        b[i][j]=a[i][j];
                Fill(0,y1,w-1,y2);
                if (check())
                {
                    for (int i=0;i<n;i++)
                    {
                        for (int j=0;j<m;j++)
                            cout<<a[i][j];
                        cout<<endl;
                    }
                    return 0;
                }
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        a[i][j]=b[i][j];
            }
        }
        else if (h>w)
        {
            if (y2>=h-1)
            {
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        b[i][j]=a[i][j];
                Fill(x1,y2-h+1,x2,y2);
                if (check())
                {
                    for (int i=0;i<n;i++)
                    {
                        for (int j=0;j<m;j++)
                            cout<<a[i][j];
                        cout<<endl;
                    }
                    return 0;
                }
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        a[i][j]=b[i][j];
            }
            if (m-y1>=h)
            {
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        b[i][j]=a[i][j];
                Fill(x1,y1,x2,y1+h-1);
                if (check())
                {
                    for (int i=0;i<n;i++)
                    {
                        for (int j=0;j<m;j++)
                            cout<<a[i][j];
                        cout<<endl;
                    }
                    return 0;
                }
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        a[i][j]=b[i][j];
            }
            if (m>=h)
            {
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        b[i][j]=a[i][j];
                Fill(x1,0,x2,h-1);
                if (check())
                {
                    for (int i=0;i<n;i++)
                    {
                        for (int j=0;j<m;j++)
                            cout<<a[i][j];
                        cout<<endl;
                    }
                    return 0;
                }
                for (int i=0;i<n;i++)
                    for (int j=0;j<m;j++)
                        a[i][j]=b[i][j];
            }
        }
    }


    if (check())
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                cout<<a[i][j];
            cout<<endl;
        }
    }
    else
        cout<<-1<<endl;
}