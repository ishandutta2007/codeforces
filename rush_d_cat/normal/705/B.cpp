#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
typedef __int64 ll;
int main()
{
    ll n, i, sum = 0, tmp;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> tmp;
        sum += (tmp - 1);
        if(sum % 2 == 1)
        {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
    return 0;
}