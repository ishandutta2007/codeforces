                            
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char s[100];
int a[102];
int main()
{
    int n;cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    getchar();
    bool ok = 1;
    for(int i = 1; i <= n; i++)
    {
        gets(s);
        int len = strlen(s);
        int cnt = 0;
        for(int j = 0; j < len; j++)
        {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y') cnt++;
        }
        if(cnt != a[i]) ok = 0;
    }
    if(ok) cout << "YES";
    else cout << "NO";
}