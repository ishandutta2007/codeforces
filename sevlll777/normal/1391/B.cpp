#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#pragma GCC optimize ("-O3")
 
using namespace std;
 
#define watch(x) cout << (#x) << " = " << (x) << endl
#define PI double(2 * acos(0.0))
#define ll long long
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define INF 1e15
 
 


int main()  {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int t;
        cin>>t;
        while(t--){
        int n,m;
        cin>>n>>m;
        char a[n][m];
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            cin>>a[i][j];
          }
        }
        int ans=0;
        for(int i=0;i<m-1;i++){
          if(a[n-1][i]=='D'){
            ans++;
          }
        }
        for(int i=0;i<n-1;i++){
          if(a[i][m-1]=='R'){
            ans++;
          }
        }
        cout<<ans<<endl;
        }
        return 0;
        }