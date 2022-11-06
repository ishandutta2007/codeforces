#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110; 
char a[N], b[N];

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%s%s", a, b);
        sort(a, a+n);
        sort(b, b+m);
        int la=0, lb = 0, cnta = 0, cntb = 0;
        while(la < n && lb < m)
        {
            if(cnta >= k)
            {
                printf("%c", b[lb++]);
                cntb ++;
                cnta = 0;
            }
            else if(cntb >= k)
            {
                printf("%c", a[la++]);
                cnta ++;
                cntb = 0;
            }
            else if(a[la] > b[lb] && cntb < k) 
            {
                printf("%c", b[lb++]);
                cntb ++;
                cnta = 0;
            }
            else if(a[la] < b[lb] && cnta < k)
            {
                printf("%c", a[la++]);
                cnta ++;
                cntb = 0;
            }
        }
        puts("");
    }
    return 0;
}