#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);

        sum += t;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int mySum = 0, i;
    for (i = 0; i < v.size(); i++) {
        mySum += v[i];

        if (mySum > sum - mySum)
            break;
    }

    cout << i + 1 << endl;
    return 0;
}