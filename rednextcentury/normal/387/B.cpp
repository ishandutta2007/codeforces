# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>
# include <ios>
# include <vector>
using namespace std;
int a[10000];
int b[10000];
bool visited[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int x=0;x<m;x++)
        cin>>b[x];
    int finished=0;
    int x=0;
    for (int i=0;i<n;i++)
    {
        for (;x<m;x++)
        {
            if (b[x]>=a[i])
            {
                finished++;
                x++;
                break;
            }
        }
    }
    cout<<n-finished<<endl;
}