#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s[110000];
int a[5000];

int main()
{
gets(s);
int n = strlen(s);
long long res = 0;
for (int i = 0; i < n; i ++)
a[s[i] + 1000] ++;
for (int i = 0; i < 5000; i ++)
res += (long long)(a[i]) * (long long)(a[i]);
cout << res << endl;
return 0;
}