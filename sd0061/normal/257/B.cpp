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
#include <map>
#define pb push_back
#define mp make_pair
#define N 1025
#define M 20005
using namespace std;
int n , m , k , a[N];


bool work()
{
  cin>>n>>m;
  cout<<max(n,m)-1<<' '<<min(m,n);
}

int main()
{
  work();
  return 0;
}