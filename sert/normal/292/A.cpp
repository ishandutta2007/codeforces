#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1e5 + 2;
#define fr(i, n) for(int i = 0; i < n; i++)

int q, n, t, it, ic;
bool start = true;
int t0, mq;

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n;

    fr(i, n){
        cin >> it >> ic;
        if (start) t0 = it;
        start = false;

        q -= it - t0;
        if (q < 0) q = 0;
        t0 = it;
        q += ic;

        mq = max(mq, q);

    }

    cout << it + q << " " << mq << "\n";

    return 0;
}