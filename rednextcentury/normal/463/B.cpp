#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define mid (l+r)/2
using namespace std;
long long a[1000000];
int main()
{
    long long n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    long long now=-a[0];
    long long best=0;
    if (now<best)
        best=now;
    for (int i=0;i<n-1;i++)
    {
        now+=a[i]-a[i+1];
        if (now<best)
            best=now;
    }
    cout<<-best<<endl;

}