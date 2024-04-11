#include <iostream>
using namespace std;
int n, k;
char s[6];

int query(int l, int r)
{
    printf("%d %d %d\n", 1, l, r);
    fflush(stdout);

    scanf("%s", s + 1);

    if (s[1] == 'N') // l > r 
    {
        return 1;
    }

    return 0;
}

int cac(int L, int R)
{
    //printf("L: %d R: %d\n", L, R);
    while (R > L) 
    {
        int mid = (L + R) >> 1;
        if ( !query(mid, mid + 1) )
        {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    return L;
}

int main()
{
    scanf("%d %d", &n, &k);
    int p1 = cac(1, n);
    int p2;
    if (p1 != n) p2 = cac(p1 + 1, n);
    else p2 = cac(1, p1 - 1);

    if ( query(p2, p1) ) p2 = cac(1, p1 - 1);
    printf("2 %d %d\n", p1, p2);
}