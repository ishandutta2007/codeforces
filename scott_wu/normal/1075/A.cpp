#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll N, A, B;
    cin >> N >> A >> B;
    if (A + B <= N + 1)
        cout << "White\n";
    else
        cout << "Black\n";
}