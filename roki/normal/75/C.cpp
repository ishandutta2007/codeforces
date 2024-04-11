#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
     int a, b;
    cin >> a >> b;

    int g = gcd(a, b);

    vector<int> faq;

    for (int i = 1; i * i <= g; ++i)
    {
        if(g % i == 0)
        {
            faq.pb(i);
            if(g != i * i)
                faq.pb(g / i);
        }
    }
    
    sort(faq.begin(), faq.end());

    int n;
    cin >> n;
    forn (i, n)
    {
        int l, r;
        cin >> l >> r;
        int j = int(upper_bound(faq.begin(), faq.end(), r) - faq.begin());
        if(j == faq.size())
            j--;
        while(j >= 0 && faq[j] > r)
            j--;
        if(j >= 0 && faq[j] >= l && faq[j] <= r)
            cout << faq[j] << endl;
        else
            cout << -1 << endl;

    }

    return 0;
}