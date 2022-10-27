#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
map<LL, LL> mp;
int type = -1;
LL LEN = -1, cnt = -1;

void solve(LL x, LL A)
{
    if (x > A)
    {
        type = 1; cnt = A;
    }

    if (x == A)
    {
        type = 2; cnt = x;
    }

    if (x < A)
    {
        type = 3;
        cnt = (x - 1);
        LEN = A - (x-1);
        if (LEN % 2 == 0)
        {
            LEN ++;
            cnt --;
        }
    }
}

LL n, k, p, pos;

int main()
{
    cin >> n >> k >> p;

    solve(k, n - k);

    for (int i = 1; i <= p; i ++) 
    {
        cin >> pos;
        //pos = i;
        if (k == 0)
        {
            printf("."); continue;
        }

        if (k == n)
        {
            printf("X"); continue;
        }

        if (k == 1)
        {

            if (pos == n) printf("X");
            else printf(".");
        
            continue;
        }


        if (type == 2)
        {
            
            if (pos <= 2*cnt - 1 && pos % 2 == 1)
            {
                printf(".");
            } else {
                printf("X");
            }

        }

        if (type == 1)
        {
            if (pos <= 2*cnt - 1 && pos % 2 == 1)
            {
                printf(".");
            } else {
                printf("X");
            }
        }

        if (type == 3)
        {
            if (pos <= LEN)
            {
                printf(".");
                continue;
            }
            pos -= (LEN + 1);

            if (pos <= 2*cnt-1 && pos % 2 == 1)
            {
                printf(".");
            } else {
                printf("X");
            }
        }

    }
    printf("\n");
}