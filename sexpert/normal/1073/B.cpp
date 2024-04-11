#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int main()
{
    int n;
    cin >> n;
    int a[MAXN], ans[MAXN], left[MAXN];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        left[a[i]] = i;
    }
    int numRem = 0;
    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        int lt = left[b];
        if(numRem <= lt)
        {
            ans[i] = lt - numRem + 1;
            numRem += lt - numRem + 1;
        }
        else
            ans[i] = 0;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}