#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair <int, int> a[100500];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + n);

    for (int i = 0; i < n - 1; i++)
        if (a[i].first < a[i + 1].first && a[i].second > a[i + 1].second) {
            cout << "Happy Alex\n";
            return 0;
        }
    cout << "Poor Alex\n";
    return 0;
}