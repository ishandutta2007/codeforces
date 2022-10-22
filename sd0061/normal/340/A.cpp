#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int x , y , a , b;

void work()
{
  cin >> x >> y >> a >> b;
  x = x * y / __gcd(x , y);
  cout << b / x - (a - 1) / x;
}

int main()
{

 // freopen("~input.txt","r",stdin);
  //while (scanf("%d",&n) , n)
  //int _; cin >> _;while (_--)
    work();
  return 0;
}