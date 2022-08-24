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
    int N; cin >> N;
    string s;
    cin >> s;
    int M = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '8')
            M++;

    cout << min (M, N / 11) << "\n";
}