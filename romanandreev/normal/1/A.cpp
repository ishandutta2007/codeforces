#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
#define ll int64_t
int main() {
  //freopen(".in","r",stdin);
  //freopen(".out","w",stdout);
  ll n,m,a;
  cin>>n>>m>>a;
  ll x=n/a;
  if (n%a!=0) x++;
  ll y=m/a;
  if (m%a!=0) y++;
  cout<<x*y;
  return 0;
}