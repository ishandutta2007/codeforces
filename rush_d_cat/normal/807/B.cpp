#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int p, x, y;
vector<int> v[502];
int main()
{
    cin >> p >> x >> y;
    for(int i=1;i<=80000;i++)
    {
        int t = i/50%475;
        for(int j=1;j<=25;j++)
        {
            t = (t * 96 + 42) % 475;
            v[t+26].push_back(i);
        }
    }
    int ans = 10000000;
    for(int i=0;i<v[p].size();i++)
    {
        //cout << v[p][i] << endl;
        if(v[p][i] < y)
        {
            continue;
        }
        int tmp = 10000000;
        if(v[p][i] >= x && (v[p][i]-x) % 50 == 0)
        {
            //cout << v[p][i] << endl;
            tmp = (v[p][i]-x+50) / 100;
        }
        if(v[p][i] <= x && (x-v[p][i]) % 50 == 0)
        {
            //cout << v[p][i] << endl;
            tmp = 0;
        }
        ans = min(ans, tmp);
    }
    if(ans == 10000000) ans = -1;
    cout << ans << endl;

    
}