#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct number
{
    int a[700];
    void set0()
    {
        for (int i = 0; i < 700; i ++)
            a[i] = 0;
    }
    int len()
    {
        for (int i = 699; i >= 0; i --)
            if (a[i] != 0) return i;
        return 0;
    }
};

number operator + (number A, number B)
{
    number C;
    C.set0();
    for (int i = 0; i < 700; i ++)
        C.a[i] = A.a[i] + B.a[i];
    for (int i = 0; i < 690; i ++)
        C.a[i + 1] += C.a[i] / 10, C.a[i] %= 10;
    return C;
}

bool great(number A, number B)
{
    if (A.len() > B.len()) return true;
    if (A.len() < B.len()) return false;

    int x = A.len();
    for (int i = x; i >= 0; i --)
        if (A.a[i] > B.a[i]) return true; else
        if (A.a[i] < B.a[i]) return false;
    return true;
}

number p2[3000];
number d[6000];
int n;
int mode[6000], v[6000];
char s[60];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i ++)
    {
        gets(s);
        if (sscanf(s, "win %d", &v[i]) == 1)
            mode[i] = 1; else
            sscanf(s, "sell %d", &v[i]), mode[i] = 2;
    }

    p2[0].a[0] = 1;
    for (int i = 1; i <= 2000; i ++)
        p2[i] = p2[i - 1] + p2[i - 1];


    for (int i = 1; i <= n; i ++)
    {
        d[i] = d[i - 1];
        if (mode[i] == 1) continue;
        int u = -1;
        for (int j = i - 1; j >= 1; j --)
            if (v[j] == v[i]) {u = j; break;}
        if (u != -1)
        {
            number r = d[u - 1] + p2[v[i]];
            if (great(r, d[i]))
                d[i] = r;
        }
    }

    int x = d[n].len();
    for (int i = x; i >= 0; i --)
        printf("%d", d[n].a[i]);
    printf("\n");

    return 0;
}