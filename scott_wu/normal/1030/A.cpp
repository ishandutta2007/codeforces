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
    int N, x;
    int h = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        h |= x;
    }
    cout << ((h) ? "HARD" : "EASY");
}