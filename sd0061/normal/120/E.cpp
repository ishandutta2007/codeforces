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
#include <utility>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 105
#define LL long long

void work()
{
  int t , n; cin >> t;
  while (t --)
    cin >> n , cout << 1 - (n & 1) << endl;

}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  work();
  return 0;
}