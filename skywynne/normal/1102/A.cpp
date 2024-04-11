#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    return !printf("%d", (n + 1) % 4 > 1);
}