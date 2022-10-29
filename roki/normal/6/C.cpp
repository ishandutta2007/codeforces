#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n)
        cin >> a[i];
    int l = 0,r = n - 1, al = 0, ar = 0, t = 0;
    int suml = 0, sumr = 0;
    while(l <= r)
    {
        if(a[l] - t + suml == a[r] - t + sumr)
        {
            if(l == r)
            {
                al++;
                break;
            }
            t += a[l] - t + suml;
            suml += a[l++];
            al++, ar++;
            sumr += a[r--];
            continue;
        }
        if(a[l] - t + suml < a[r] - t + sumr)
        {
            t += a[l] - t + suml;
            suml += a[l++];
            al++;   
        }
        else
        {
            sumr += a[r];
            t += a[r--] - t + sumr;
            ar++;
        }
    }
    cout << al << ' ' << ar << endl;
}