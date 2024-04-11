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
const int MAXN = 100100;

int N;
int arr[MAXN];
int ord[MAXN];
bool win[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ord[arr[i]] = i;
    }

    for (int i = N; i >= 1; i--)
    {
        int cloc = ord[i];
        win[cloc] = false;
        for (int j = (cloc % i); j < N; j += i)
        {
            if (arr[j] > arr[cloc] && !win[j])
                win[cloc] = true;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (win[i]) cout << 'A';
        else cout << 'B';
    }
    cout << "\n";
}