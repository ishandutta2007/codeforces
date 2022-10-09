#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define uwu '\n'

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t; cin >> t;
  for(int i=0; i<t; i++){
    int n;cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }
    if (sum < n)
    {
        cout << 1 << endl;
    }
    else if (sum == n)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << sum - n << endl;
    }
  }
}