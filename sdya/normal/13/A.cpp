#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b) {return (b ? gcd(b, a % b) : a);}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 2; i < n; i ++)
    {
        int cur = n;
        while (cur > 0) res += cur % i, cur /= i;
    }

    int p = res, q = n - 2;
    int d = gcd(p, q);
    p /= d, q /= d;
    printf("%d/%d\n", p, q);


    return 0;
}