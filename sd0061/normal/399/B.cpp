#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 400005
#define foreach(it , A) for (typeof(A.begin()) it = A.begin() ; it != A.end() ; ++ it)
int n;
string s;

void work()
{
    cin >> n >> s;
    reverse(s.begin() , s.end());
    LL ans = 0;
    foreach(it , s)
        ans <<= 1 , ans |= *it == 'B';
    cout << ans << endl;
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}