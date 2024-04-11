#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long double best = 0.0, worst = 10000000.0;
    int n, k;
    cin >> n >> k;
    int num = n / k;
    int prof[110];
    for (int i = 0; i < n; i++)
        cin >> prof[i];
    bool use[110];
    for (int i = 0; i < 110; i++)
        use[i] = false;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        long double sum = 0.0;
        for (int j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            sum += prof[temp-1];
            use[temp-1] = true;
        }
        best = max (best, (long double) (sum / (num + 0.0)));
        worst = min (worst, (long double) (sum / (num + 0.0)));
    }
    vector <int> left;
    for (int i = 0; i < n; i++)
        if (!use[i])
            left.push_back (prof[i]);
    sort (left.begin(), left.end());
    if (left.size() >= num && left.size() > n - (k * num))
    {
        long double sum = 0.0;
        for (int j = 0; j < num; j++)
        {
            sum += left[j];
            if (j == num - 1)
                break;
        }
        worst = min (worst, (long double) (sum / (num + 0.0)));
        sum = 0.0;
        for (int j = left.size() - 1; j >= (left.size() - num); j--)
        {
            sum += left[j];
            if (j == left.size() - num)
                break;
        }
        best = max (best, (long double) (sum / (num + 0.0)));
    }
    cout << fixed << setprecision(6) << worst << " " << best << "\n";
    //system ("Pause");
    return 0;
}