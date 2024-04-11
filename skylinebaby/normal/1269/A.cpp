#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    if(n % 3 == 0) printf("%d %d\n", n + 6,  6);
    if(n % 3 == 1) printf("%d %d\n", n + 8,  8);
    if(n % 3 == 2) printf("%d %d\n", n + 4,  4);
    return 0;
}