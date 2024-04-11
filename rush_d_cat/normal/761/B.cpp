#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, L;
int a[60], b[60], used[200];
int main()
{
    cin >> n >> L;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];used[a[i]] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    int ok = 0;
    for(int i=0;i<L;i++)
    {
        int tmp = i;
        int ok_ = 1;
        for(int j=1;j<=n;j++)
        {
            tmp = (i + b[j]) % L;
            if(!used[tmp])
            {
                ok_ = 0;
                break;
            } 
        }
        ok |= ok_;
    }
    if(ok) cout << "YES";
    else cout << "NO";
}