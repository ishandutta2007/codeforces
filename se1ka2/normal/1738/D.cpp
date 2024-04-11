#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100005];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i <= n + 1; i++)
        {
            v[i].clear();
        }
        int b[100005];
        int left = 0, right = n + 1;
        for(int x = 1; x <= n; x++)
        {
            cin >> b[x];
            v[b[x]].push_back(x);
            if(x < b[x])
            {
                left = x;
            }
            else
            {
                right = x;
            }
        }
        int k = left;
        cout << k << endl;
        int r = 0;
        if(v[n + 1].size())
        {
            r = n + 1;
        }
        while(true)
        {
            int y = -1;
            for(int x : v[r])
            {
                if(v[x].size())
                {
                    y = x;
                }
                else
                {
                    cout << x << " ";
                }
            }
            if(y == -1)
            {
                break;
            }
            cout << y << " ";
            r = y;
        }
        cout << endl;
    }
}