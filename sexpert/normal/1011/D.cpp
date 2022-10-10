#include <bits/stdc++.h>
using namespace std;

int truths[37];
int m, n, a;

int getAns(int y)
{
    int ans;
    cout << y << '\n';
    fflush(stdout);
    cin >> ans;
    if(ans == 0 || ans == -2) exit(0);
    return ans;
}

void bs()
{
    int low = 1, hi = m, mid, i = 0;
    while(low != hi)
    {
        mid = (low + hi + 1)/2;
        a = truths[i%n]*getAns(mid);
        if(a == 1) low = mid;
        else hi = mid - 1;
        i++;
    }
    getAns(hi);
}

int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        a = getAns(m);
        if(a == -1) truths[i] = 1;
        else truths[i] = -1;
    }
    bs();
}