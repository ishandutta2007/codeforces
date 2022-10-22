#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 2005
int n , H , m1 , m2;
pair<int , int> a[N];
pair<int , int> b[N];

void work()
{
    int i , j , k , x , y;
    scanf("%d%d",&n,&H);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d%d",&j,&x,&y);
        if (j)
            a[m1 ++] = make_pair(x , y);
        else
            b[m2 ++] = make_pair(x , y);
    }
    sort(a , a + m1);
    sort(b , b + m2);
    set< pair<int , int> > h1 , h2;
    set< pair<int , int> >::iterator it;
    bool t = 0; int ans = 0;
    i = j = 0 , k = H;
    int sum = 0;
    while (1) {
        while (i < m1 && a[i].first <= k) {
            h1.insert(make_pair(a[i].second , i));
            ++ i;
        }
        while (j < m2 && b[j].first <= k) {
            h2.insert(make_pair(b[j].second , j));
            ++ j;
        }
        if (t) {
            if (!h1.size()) break;
            it = -- h1.end();
            ++ sum , k += it -> first;
            h1.erase(it);
        } else {
            if (!h2.size()) break;
            it = -- h2.end();
            ++ sum , k += it -> first;
            h2.erase(it);
        }
        t ^= 1;
    }
    ans = max(ans , sum);

    h1.clear() , h2.clear();
    t = 1;
    i = j = 0 , k = H;
    sum = 0;
    while (1) {
        while (i < m1 && a[i].first <= k) {
            h1.insert(make_pair(a[i].second , i));
            ++ i;
        }
        while (j < m2 && b[j].first <= k) {
            h2.insert(make_pair(b[j].second , j));
            ++ j;
        }
        if (t) {
            if (!h1.size()) break;
            it = -- h1.end();
            ++ sum , k += it -> first;
            h1.erase(it);
        } else {
            if (!h2.size()) break;
            it = -- h2.end();
            ++ sum , k += it -> first;
            h2.erase(it);
        }
        t ^= 1;
    }
    ans = max(ans , sum);
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}