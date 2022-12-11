#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 1e6 + 5;
int h1, m1, h2, m2;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d:%d\n%d:%d", &h1, &m1, &h2, &m2);

    h1 -= h2;
    m1 -= m2;

    if (m1 < 0) {
        m1 += 60;
        h1--;
    }

    if (h1 < 0)
        h1 += 24;

    if (h1 < 10) printf("0");
    printf("%d:", h1);
    if (m1 < 10) printf("0");
    printf("%d\n", m1);


    return 0;
}