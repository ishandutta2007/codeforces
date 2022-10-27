/*



ttcheck
1e5*1e5O(n*n)T


n/1+n/2+n/3... = O(nlog(n))


i
tv1[t]<v1[t]1
v1[t]+121

st


*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int NICO = 200000 + 10;
int v1[NICO], v2[NICO];
vector< pair<int, int> > sol;
int n, c, a, b, i, j, ls, ld;
int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> c;
        if(c == 1)
            a++,v1[a] = i;
        else
            b++,v2[b] = i;
    }
    for(i = 1; i <= 2*n; i++)
    {
        if(v1[i] == 0)
            v1[i] = n+1;
        if(v2[i] == 0)
            v2[i] = n+1;
    }
    for(i = 1; i <= n; i++)
    {
        j = a = b = ls = ld = 0;
        while(j < n)
        {
            if(v1[i + a] < v2[i + b])
            {
                ls++;
                c = ls;
                j = v1[i + a];
                a += i;
                b = j - a;
            }
            else
            {
                ld++;
                c = ld;
                j = v2[i + b];
                b += i;
                a = j - b;
            }
        }
        if(j==n &&ls != ld && max(ls,ld) == c)
            sol.push_back(make_pair( c, i ));
    }
    sort(sol.begin(), sol.end());
    cout<<sol.size()<<'\n';
    for(i = 0; i < sol.size(); i++)
        cout<<sol[i].first<<" "<<sol[i].second<<'\n';
    return 0;
}