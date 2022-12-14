#include<iostream>
using namespace std;
int vis[1000];
int main()
{
    int num=0;
    int n;
    cin>>n;
    for (int i=0;i<2;i++)
    {
        int m;
        cin>>m;
        for (int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            if (++vis[x]==1)
                num++;
        }
    }
    if (num==n)
        cout<<"I become the guy.\n";
    else
        cout<<"Oh, my keyboard!\n";
}