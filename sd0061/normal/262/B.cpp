#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 100005
#define M 300005
int n , K;
multiset<int> h;
void work()
{
    int x , ans = 0;
    scanf("%d%d",&n,&K);
    while (n --)
        scanf("%d",&x) , h.insert(x);
    while (K --)
        x = *h.begin() , h.erase(h.begin()) , h.insert(-x);
    for (multiset<int>::iterator it = h.begin() ; it != h.end() ; ++ it)
        ans += *it;
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}