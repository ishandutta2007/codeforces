#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

char a[300100], b[300100], c[300100];

int main() {
    scanf("%s%s", a, b);
    int n = strlen(a);
    sort(a, a + n);
    sort(b, b + n);
    c[n] = 0;
    int i = 0, j = n - 1, l = 0, r = n;
    bool wasa = false, wasb = false;
    forn (q, n) {
//        cerr << a[i] << " " << b[j] << endl;
        if (q % 2 == 0) {
            if (a[i] < b[j]) {
                c[l++] = a[i++];
            } else {
                if (!wasa) {
                    wasa = true;
                    i += (n - q - 1) / 2;
                }
                c[--r] = a[i--];
            }
        } else {
            if (a[i] < b[j]) {
                c[l++] = b[j--];
            } else {
                if (!wasb) {
                    wasb = true;
                    j -= (n - q - 1) / 2;
                }
                c[--r] = b[j++];
            }
        }
    }
    printf("%s", c);
    return 0;
}