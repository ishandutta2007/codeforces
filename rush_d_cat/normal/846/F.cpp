#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
vector<int> vec[1000000+10];
int n, x;


int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= 1000000; i ++)
    {
        vec[i].push_back(0);
    }


    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &x);
        vec[x].push_back(i);
    }

    for (int i = 1; i <= 1000000; i ++)
    {
        vec[i].push_back(n + 1);
    }

    double res = 0;
    for (int i = 1; i <= 1000000; i ++)
    {
        LL sum = 0; LL cnt = (LL)n * (LL)n;
        for (int j = 1; j < vec[i].size(); j ++)
        {
            LL dis = vec[i][j] - vec[i][j-1] - 1;
            sum += dis * dis;
        }
        res += (double)(cnt - sum) / cnt;
    }
    printf("%.7f\n", res);
}