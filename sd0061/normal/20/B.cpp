#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define N 100005
typedef long long LL;
#define fi first
#define se second
using namespace std;
void work()
{
    long long A , B , C , D;
    vector<double> ans;
    cin >> A >> B >> C;
    if (A == 0 && B == 0 && C == 0)
    {
        cout << "-1" << endl;
        return;
    }

    if (A == 0)
    {
        if (B == 0)
        {
            cout << "0" << endl;
        } else
        {
            printf("1\n");
            printf("%.10lf\n", -(double)(C) / (double)(B));
        }
        return;
    } else
    {
        D = B * B - 4LL * A * C;
        if (D < 0)
        {
            printf("0\n");
        } else
        if (D == 0)
        {
            printf("1\n");
            printf("%.10lf\n", -(double)(B) / (double)(A) / 2.0);
        } else
        {
            printf("2\n");
            double x1 = (-(double)(B) + sqrt((double)(D))) / ((double)(A)) / 2.0;
            double x2 = (-(double)(B) - sqrt((double)(D))) / ((double)(A)) / 2.0;
            ans.push_back(x1);
            ans.push_back(x2);
            sort(ans.begin(), ans.end());
            printf("%.10lf\n", ans[0]);
            printf("%.10lf\n", ans[1]);
        }
    }
    return;
}

int main()
{
  work();
  return 0;
}