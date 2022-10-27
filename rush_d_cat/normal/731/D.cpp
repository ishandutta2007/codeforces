#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000000 + 10;
int n, c, l[MAXN], sum[MAXN];
vector<int> vec[MAXN];
int main()
{
    int i, j, check = 0;
    scanf("%d %d", &n, &c);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &l[i]);
        for(j = 1; j <= l[i]; j++)
        {
            int x; scanf("%d", &x);
            vec[i].push_back(x);
        }
    }
    for(i = 1; i <= n-1; i++)
    {
        for(j = 0; j < min(vec[i].size(), vec[i+1].size()); j++)
        {
            if(vec[i][j] < vec[i+1][j])
            {
                sum[c - vec[i+1][j] + 1] ++;
                sum[c - vec[i][j] + 1] --;
            } else if(vec[i][j] > vec[i+1][j]) {
                sum[0]++;
                sum[c - vec[i][j] + 1]--;
                sum[c - vec[i+1][j] + 1] ++;
                sum[c]--;
            }
            if(vec[i][j] != vec[i+1][j]) break;
        }

        if(j >= vec[i+1].size() && vec[i+1].size() < vec[i].size() )
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int res = 0;
    for(i = 0; i < c; i++)
    {
        res += sum[i];
        if(res == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

}