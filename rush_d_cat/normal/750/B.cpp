#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[10];
int n, d;
int main()
{
    cin >> n;
    int dis = 0;
    int ok = 1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &d);
        scanf("%s", s+1);
        if(dis == 0 && s[1] != 'S') ok = 0;
        if(dis == 20000 && s[1] != 'N') ok = 0;
        if(s[1] == 'S') dis += d;
        if(s[1] == 'N') dis -= d;
        if(dis<0 || dis>20000) ok = 0;
    }
    if(dis != 0) ok = 0;
    cout << (ok?"YES":"NO") << endl;
}