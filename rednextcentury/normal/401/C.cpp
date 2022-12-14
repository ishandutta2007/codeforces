# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int kok=m/2;
    if (m%2!=0)
        kok++;
    if (n-m>1 || kok-n>1)
        cout<<-1<<endl;
    else
    {
    int g_2=m/2;
    int g_1=m%2;
    while (g_2>0)
    {
        if (g_1+g_2==n || g_1+g_2==n-1 || g_1+g_2==n+1)
            break;
        g_2--;
        g_1+=2;
    }
    if (g_1+g_2<n)
    {
        cout<<0;
        n--;
    }
    while (true)
    {
        if (g_1>0)
        {
            cout<<1;
            g_1--;
        }
        else if (g_2>0)
        {
            cout<<11;
            g_2--;
        }
        if (n>0)
        {
            cout<<0;
            n--;
        }
        if (g_1==0 && g_2==0 && n==0)
            break;
    }
    cout<<endl;
    }
}