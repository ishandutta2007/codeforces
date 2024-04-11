#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
int a[N],b[N];
char s[N];

int main()
{
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    memset(a,0,sizeof(a));
    for(int i = 1; i <= n; i ++) {
      if(s[i] == 'm' && s[i + 1] == 'e' && s[i + 2] == 't' && s[i + 3] == 'a' && s[i + 4] == 'l') 
          a[i] = 1;
    }
    for(int i = n; i >= 1; i --) 
        a[i] += a[i + 1];
    long long ans = 0;
    for(int i = 1; i <= n; i ++)
      if(s[i] == 'h' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'v' && s[i + 4] == 'y')
          ans += a[i];
    cout << ans << endl;
    return 0;
}