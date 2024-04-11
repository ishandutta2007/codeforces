#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <math.h>

using namespace std;

long long A, B, C, D;

vector < double > ans;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> A >> B >> C;
    if (A == 0 && B == 0 && C == 0)
    {
        cout << "-1" << endl;
        return 0;
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
        return 0;
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
    return 0;
}