#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
int arr[55];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int x = 1e9;
    for (int i = 0; i < N; i++)
        x = min (x, arr[i]);
    int cx = 0;
    for (int i = 0; i < N; i++)
        if (x == arr[i]) cx++;

    if (cx * 2 > N)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}