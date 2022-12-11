#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

int n, m, k, a[3], b, sum, pr;
int pt, vs;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> a[0] >> a[1];

    sort(a, a + 2);
    pr = (a[0] + 1) % 2;
    a[pr]--;
    int h = 1;

    while(true){
        if (a[0] == 0 && a[1] == 0)
            break;
        if (a[0] == 0)
            k = 1;
        else if (a[1] == 0)
            k = 0;
        else if (h == 1)
            k = 1 - pr;
        else if (h == 0)
            k = pr;
        a[k]--;
        if (k == pr)
            pt++;
        else
            vs++;
        h = 1 - h;
        pr = k;
    }

    cout << pt << " " << vs;

    return 0;
}