#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int arr[MAXN];


int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);
    cout << arr[(N-1)/2] << "\n";
}