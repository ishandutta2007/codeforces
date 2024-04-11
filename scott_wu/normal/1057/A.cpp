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
int arr[200100];
vector <int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 2; i <= N; i++)
        cin >> arr[i];
    while (N > 1)
    {
        ans.push_back(N);
        N = arr[N];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i << " ";
    cout << "\n";
}