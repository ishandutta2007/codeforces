# include <iostream>
# include <string>
# include <vector>
# include <stdio.h>
# include <map>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int y,x,j;
        cin>>x>>y;
        int s=i-y;
        int num=0;
        for (j=1;j*j<x;j++)
        {
            if (x%j==0)
            {
                int x1=x/j;
                int x2=j;
                if (a[x1]<s)
                    num++;
                if (a[x2]<s)
                    num++;
                a[x1]=i,a[x2]=i;
            }
        }
        if (j*j==x)
        {
            if (a[j]<s)
                num++;
            a[j]=i;
        }
        cout<<num<<endl;
    }
}