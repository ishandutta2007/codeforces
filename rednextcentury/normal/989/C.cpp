#include <bits/stdc++.h>

using namespace std;
char a[100][100];

int main()
{
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int sz1 = 41, sz2 = 9;
    int sz = 49;
    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<sz1;j++)
        {
            if (i%2 || j%2==0)a[i][j]='A';
            else a[i][j] = '.';
        }
    }
    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<sz2;j++)
        {
            if (i%2 || j%2==0)a[i][sz1+j]='B';
            else a[i][j+sz1] = '.';
        }
    }
    A--,B--;
    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<sz1;j++)
        {
            if (a[i][j]=='.')
            {
                if (B)B--,a[i][j]='B';
                else if (C)C--,a[i][j]='C';
                else if (D)D--,a[i][j]='D';
                else a[i][j]='A';
            }
        }
    }
    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<sz2;j++)
        {
            if (a[i][j+sz1]=='.')
            {
                if (A)A--,a[i][j+sz1]='A';
                else a[i][j+sz1]='B';
            }
        }
    }
    assert(A+B+C+D==0);
    cout<<sz<<' '<<sz1+sz2<<endl;
    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<sz1+sz2;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}