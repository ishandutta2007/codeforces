#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        if(i == n)
        {
            if(i % 2)
            {
                printf("I hate it");
            } else {
                printf("I love it");
            }
            break;
        }
        if(i % 2)
        {
            printf("I hate that ");
        } else {
            printf("I love that ");
        }
    }
    return 0;
}