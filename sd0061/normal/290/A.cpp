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
#define PB push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
#define M 100005
#define LL long long
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}

void work()
{
  vector<string> A;

A.PB(" "); A.PB("Washington"); A.PB("Adams");
A.PB("Jefferson"); A.PB("Madison"); A.PB("Monroe"); A.PB("Adams"); A.PB("Jackson");
A.PB("Van Buren"); A.PB("Harrison"); A.PB("Tyler"); A.PB("Polk"); A.PB("Taylor");
A.PB("Fillmore"); A.PB("Pierce"); A.PB("Buchanan"); A.PB("Lincoln"); A.PB("Johnson");
A.PB("Grant"); A.PB("Hayes"); A.PB("Garfield"); A.PB("Arthur"); A.PB("Cleveland");
A.PB("Harrison"); A.PB("Cleveland"); A.PB("McKinley"); A.PB("Roosevelt"); A.PB("Taft");
A.PB("Wilson"); A.PB("Harding"); A.PB("Coolidge"); A.PB("Hoover");
A.PB("Roosevelt"); A.PB("Truman"); A.PB("Eisenhower"); A.PB("Kennedy");
A.PB("Johnson"); A.PB("Nixon"); A.PB("Ford"); A.PB("Carter"); A.PB("Reagan"); A.PB("Bush"); A.PB("Clinton");
  int x;
  cin >> x;
  cout << A[x];
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  //init();
  //int _;cin>>_;while(_--)
  //while(RD(n) , n)
    work();
  return 0;
}