#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define rep(i, s, n) for(int (i)=(int)(s); (i)<(int)(n); ++i)
#define READ2(a, b) int (a), (b); cin >> (a) >> (b);

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<string> vs; 
typedef vector<vs> vvs;
typedef long double ld; 
typedef vector<ld> vd; 
typedef pair<int,int> pii; 
typedef vector<pii> vp; 
typedef queue<int> qi; 
typedef queue<pii> qp; 
typedef map<int,string> mis; 
typedef map<string,int> msi; 
typedef map<string,string> mss; 
typedef long long ll; 

int main()
{
  ios_base::sync_with_stdio(false);
  int n, m = 0;
  cin >> n;
  vi ws(n);
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    m = max(m, x);
    ws[i] = x; 
  }
  vi factors(m+2, 0);
  rep(i, 0, n)
  {
    factors[ws[i]]++;
  }
  int answer = 0;
  int add;
  rep(i, 0, (m+1))
  {
    int rest = factors[i] % 2;
    add = factors[i] / 2;
    factors[i+1] += add;
    answer += rest;
  }
  add = factors[m+1];
  while(add)
  {
     int rest = add % 2;
     answer += rest;
     add = add/2;
  }
  cout << answer << endl;
  return 0;
}