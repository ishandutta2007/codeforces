#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int count[10005];
        memset(count, 0, sizeof(count));
        pair<long long, long long> chosen = {20000ll, 1ll};
        vector<long long> sides;
        for(int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            count[a]++;
            if(count[a]%2 == 0) sides.push_back(a);
        }
        sort(sides.begin(), sides.end());
        for(int j = 0; j < sides.size() - 1; j++)
        {
            long long x = sides[j], y = sides[j + 1];
            long long a = chosen.first, b = chosen.second;
            if(a*b*(x*x + y*y) < x*y*(a*a + b*b)) chosen = make_pair(x, y);
        }
        cout << chosen.first << " " << chosen.first << " " << chosen.second << " " << chosen.second << endl;
    }
}