#include <iostream>
using namespace std;
int n, m, x, y, gg[1002];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y;gg[x]=1, gg[y] = 1;
    }
    int hui = 0;
    for(int i=1;i<=n;i++)
    {
        if(!gg[i])
        {
            hui = i;
            break;
        }
    }
    cout << (n-1) << endl;
    for(int i=1;i<=n;i++)
    {
        if(i!=hui)cout << hui << " " << i << endl; 
    }
}