#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;

    int N = s.length();
    int nrow = (N - 1) / 20 + 1;
    int ncol = (N - 1) / nrow + 1;

    cout << nrow << " " << ncol << "\n";
    for (int i = 0; i < nrow; i++)
    {
        int nstart = i * N / nrow, nend = (i + 1) * N / nrow;
        for (int j = nstart; j < nend; j++)
            cout << s[j];
        for (int j = nend; j < nstart + ncol; j++)
            cout << "*";
        cout << "\n";
    }
}