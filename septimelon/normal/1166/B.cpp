#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, d1, d2;
    string gla("aeiouaeiou");
    string wor("");
    d1 = 5;
    cin >> k;
    bool its = false;
    if (k >= 25)
        while (d1*5 <= k) {
            if (k%d1 == 0) {
                its = true;
                d2 = k/d1;
                break;
            }
            d1++;
        }
    if (!its) {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            wor += gla[j%5+i%5];
        }
    }
    cout << wor << endl;
    return 0;
}