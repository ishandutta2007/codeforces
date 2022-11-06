#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
   int T;
   cin >> T;
   while(T-- > 0) {
       int n;
       cin >> n;
       vector<int> a(n);
       REP(i, n) cin >> a[i];
       sort(a.begin(),a.end());
       cout << min(n-2, a[a.size()-2]-1) << endl;
   } 
}