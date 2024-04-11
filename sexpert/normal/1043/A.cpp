#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0, k = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        k = max(k, x);
        sum += x;
    }
    while(sum >= n*k - sum)
    {
        k++;
    }
    cout << k << endl;
}