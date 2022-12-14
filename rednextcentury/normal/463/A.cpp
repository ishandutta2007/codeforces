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
struct sugar
{
    int d;
    int c;
};
bool comp(sugar a1,sugar a2)
{
    return a1.c<a2.c;
}
sugar a[100000];
int main()
{
    int n,s;
    cin>>n>>s;
    for (int i=0;i<n;i++)
        cin>>a[i].d>>a[i].c;
    sort(a,a+n,comp);
    int best=0;
    bool is=0;
    for (int i=0;i<n;i++)
    {
        if (a[i].d>s)
            continue;
        if (a[i].d==s && a[i].c>0)
            continue;
        is=1;
        if (100-a[i].c>best && a[i].c!=0)
            best=100-a[i].c,is=1;
    }
    if (is)
    cout<<best<<endl;
    else
        cout<<-1<<endl;
}