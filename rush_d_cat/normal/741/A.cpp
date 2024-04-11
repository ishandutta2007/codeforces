#include <iostream>
#include <vector>
using namespace std;
const int NICO = 102;
int vis[NICO];
int n;
int to[NICO];
vector<int> vec;
int gcd(int x, int y)
{
    return y==0?x:gcd(y,x%y);
}
int lcm(int x, int y)
{
    return x*y/gcd(x,y);
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> to[i];
    }
    int ok = 1;
    for(int i=1;i<=n;i++)
    {
        int len = 1;
        int pos = to[i];
        if(vis[i]) continue;
        while(pos != i)
        {
            len ++;
            vis[pos] = 1;
            pos = to[pos];
            if(vis[pos] && pos != i)
            {
                ok = 0;
                break;
            }
        }
        if(len%2==0) vec.push_back(len/2);
        else vec.push_back(len);
    }
    if(!ok)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 1;
    for(int i=0;i<vec.size();i++)
    {
       // cout << vec[i] << endl;
        ans = lcm(ans, vec[i]);
    }
    cout << ans << endl;
}