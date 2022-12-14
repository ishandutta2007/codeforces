#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int a[1000000];
bool used[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    int x=1;
    a[0]=1;
    int l=k;
    int now=k;
    for (int i=1;i<l;i++)
    {
        if (i%2!=0)
        a[i]=a[i-1]+k;
        else
        a[i]=a[i-1]-k;
        used[a[i]]=1;
        x++;
        k--;
    }
    for (int i=2;i<=n;i++)
    {
        if (!used[i])
        {
            a[x++]=i;
        }
    }
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
        cout<<endl;
}