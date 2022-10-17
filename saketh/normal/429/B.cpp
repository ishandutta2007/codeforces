#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int N=1024;
int d1[N][N], d2[N][N], d3[N][N], d4[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;

  int grid[n+1][m+1];
  for(int r=1; r<=n; ++r)
    for(int c=1; c<=m; ++c)
      cin >> grid[r][c];
 
 //Diagonal to the bottom right
  for(int i=n; i>=1; --i)
    for(int j=m; j>=1; --j)
      d1[i][j] = max(d1[i+1][j], d1[i][j+1]) + grid[i][j];

  //Diagonal to the bottom left
  for(int i=n; i>=1; --i)
    for(int j=1; j<=m; ++j)
      d2[i][j] = max(d2[i][j-1],d2[i+1][j]) + grid[i][j];

  //Diagonal to the top right
  for(int i=1; i<=n; ++i)
    for(int j=m; j>=1; --j)
      d3[i][j] = max(d3[i][j+1],d3[i-1][j]) + grid[i][j];

  //Diagonal to the top left
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      d4[i][j] = max(d4[i-1][j],d4[i][j-1]) + grid[i][j];

  for(int i=0; i<= n+1; ++i){
    d1[i][0] = d1[i][m+1] = -99999999;
    d2[i][0] = d2[i][m+1] = -99999999;
    d3[i][0] = d3[i][m+1] = -99999999;
    d4[i][0] = d4[i][m+1] = -99999999;
  }

  for(int j=0; j<= m+1; ++j){
    d1[0][j] = d1[n+1][j] = -99999999;
    d2[0][j] = d2[n+1][j] = -99999999;
    d3[0][j] = d3[n+1][j] = -99999999;
    d4[0][j] = d4[n+1][j] = -99999999;
  }

  int ret=0;
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
      int sum1 = d1[i+1][j] + d4[i-1][j] + d2[i][j-1] + d3[i][j+1];
      int sum2 = d1[i][j+1] + d4[i][j-1] + d2[i+1][j] + d3[i-1][j];

      ret = max(ret, sum1);
      ret = max(ret, sum2);
    }
  }
  cout << ret << endl;
}