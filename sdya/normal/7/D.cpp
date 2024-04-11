#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

char s[10000000];
int d[10000000];
int d1[10000000];
int d2[10000000];

bool p[10000000];

int main()
{
    gets(s);
    int n = strlen(s);

    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
	    int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
	    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
	    d1[i] = --k;
	    if (i+k > r)
		    l = i-k,  r = i+k;
    }

    l=0, r=-1;
    for (int i=0; i<n; ++i) {
	    int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
	    while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])  ++k;
	    d2[i] = --k;
	    if (i+k-1 > r)
		    l = i-k,  r = i+k-1;
    }

    for (int i = n; i >= 1; i --)
        d1[i] = d1[i - 1] + 1, d2[i] = d2[i - 1];

    for (int i = 1; i <= n; i ++)
    {
        if (d1[i] >= i) p[2 * i - 1] = true;
        if (d2[i] >= i - 1) p[2 * i - 2] = true;
    }

    for (int i = 1; i <= n; i ++)
        if (p[i]) d[i] = d[i / 2] + 1; else d[i] = 0;

    long long res = 0;
    for (int i = 1; i <= n; i ++)
        res += (long long)(d[i]);
    cout << res << endl;
    return 0;
}