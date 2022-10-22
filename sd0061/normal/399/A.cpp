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

void work()
{
    int n , p , k;
    cin >> n >> p >> k;
    int l = max(1 , p - k) , r = min(n , p + k);
    if (l != 1)
        cout << "<< ";
    for (int i = l ; i < p ; ++ i)
        cout << i << " ";
    cout << "(" << p << ") ";
    for (int i = p + 1 ; i <= r ; ++ i)
        cout << i << " ";
    if (r != n)
        cout << ">>" << endl;
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}