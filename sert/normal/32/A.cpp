#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long int h[10000];
    long int n, d, kol = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((h[j] - h[i] <= d))
            if ((h[j] - h[i] >= -d))
                kol++;
    cout << kol - n;
    //cout << "Hello world!" << endl;
    return 0;
}