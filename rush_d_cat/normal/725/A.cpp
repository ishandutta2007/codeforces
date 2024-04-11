#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 200000+10;
typedef long long ll;
char s[MAXN];
int ok[MAXN];
int main()
{
    int n, i, j;cin >> n;
    scanf("%s", s+1);
    int cnt = 0;
    for(i = 1; i <= n; i++)
    {
        if(s[i]=='<') cnt++;
        else break;
    }
    for(i = n; i >= 1; i--)
    {
        if(s[i]=='>') cnt++;
        else break;
    }
    cout << cnt << endl;
}