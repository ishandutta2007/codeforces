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

int N;
vector <char> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        cout << v[i];
    cout << "\n";
}