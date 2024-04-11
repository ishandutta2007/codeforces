#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string name, s;
    int score = -50000, sc, a, b, c, d, e, vz, f;


    for (int i = 0; i < n; i++)
    {
        cin >> s;
        scanf("%d%d%d%d%d%d%d", &vz, &f, &a, &b, &c, &d, &e);
        sc = vz * 100 - f * 50 + a + b + c + d + e;
        if (sc > score)
        {
          score = sc;
          name = s;
        }
    }
    cout << name;
}