# include <iostream>
# include <string>
# include <algorithm>
# include <cmath>
# include <queue>
# include <ios>
# include <map>
using namespace std;
char a[1000][1000];
int main()
{
    int n;
    cin>>n;
    int m;
    int k;
    cin>>m>>k;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            int a;
            cin>>a;
        }
    }
    cout<<m*(m-1)/2<<endl;
        for (int i=1;i<=m;i++)
        {
            for (int x=i+1;x<=m;x++)
            {
                if (k==0)
                    cout<<i<<" "<<x<<endl;
                else
                    cout<<x<<" "<<i<<endl;
            }
        }
}