#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <queue>
#include <functional>
#include <sstream>
#include <complex>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <string.h>

using namespace std;

#ifdef ONLINE_JUDGE
void init()
{
}
#else
FILE* inputstream;
FILE* outputstream;
void init()
{
    inputstream = freopen("in.txt", "r", stdin);
    outputstream = freopen("output.txt", "w", stdout);
}
#endif

int tonum_int(const string& str)
{
    int num;
    stringstream ss(str);
    ss>>num;
    return num;
}

long long num[5001];
long long sum[51];
int lind[250001];
long long lastbest[250001];

long long prebest[51];
long long midbest[51];
long long postbest[51];

void deal(int ind, int len)
{
    long long themax[5001];
    for (int i = 0; i < len; ++i)
    {
        themax[i] = num[i];
    }
    midbest[ind] = themax[0];
    for (int i = 1; i < len; ++i)
    {
        themax[i] = max(themax[i], num[i] + themax[i - 1]);
        midbest[ind] = max(midbest[ind], themax[i]);
    }
    prebest[ind] = num[0];
    long long sum = num[0];
    for (int i = 1; i < len; ++i)
    {
        sum += num[i];
        prebest[ind] = max(prebest[ind], sum);
    }
    postbest[ind] = num[len - 1];
    sum = num[len - 1];
    for (int i = len - 2; i >= 0; --i)
    {
        sum += num[i];
        postbest[ind] = max(postbest[ind], sum);
    }
}

int main()
{
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int len;
        cin >> len;
        for (int j = 0; j < len; ++j)
        {
            cin >> num[j];
            sum[i] += num[j];
        }
        deal(i, len);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> lind[i];
        lind[i]--;
    }
    long long best = -(1LL<<62);
    lastbest[0] = postbest[lind[0]];
    best = max(best, midbest[lind[0]]);
    for (int i = 1; i < m; ++i)
    {
        best = max(best, midbest[lind[i]]);
        best = max(best, lastbest[i-1] + prebest[lind[i]]);
        lastbest[i] = postbest[lind[i]];
        lastbest[i] = max(lastbest[i], lastbest[i-1] + sum[lind[i]]);
    }
    cout << best << endl;
    return 0;
    //Thanks for watching & testring)
}