#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[105];

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    int cnt=0;
    int j=0;
    while (s[j]=='0'&&j<n) j++;
    for (int i=j;i<n;i++) if (s[i]=='0') cnt++;
    if (cnt>5) puts("yes"); else puts("no");
    return 0;
}