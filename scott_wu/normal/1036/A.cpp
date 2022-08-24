#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    ll N, K;
    cin >> N >> K;
    cout << (K - 1) / N + 1 << "\n";
}