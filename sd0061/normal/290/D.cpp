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
#define pb push_back
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
char a[50][50] = {
"Washington",
"Adams",
"Jefferson",
"Madison",
"Monroe",
"Adams",
"Jackson",
"Van Buren",
"Henry",
"Tyler",
"Polk",
"Taylor",
"Fillmore",
"Pierce",
"Buchanan",
"Lincoln",
"Johnson",
"Grant",
"Hayes",
"Garfield",
"Arthur",
"Cleveland",
"Harrison",
"Cleveland",
"McKinley",
"Roosevelt",
"Howard Taft",
"Wilson",
"Harding",
"Coolidge",
"Hoover",
"Roosevelt",
"Eisenhower",
"Kennedy",
"Johnson",
"Nixon",
"Ford",
"Carter",
"Reagan",
};

void work()
{
  string s;int n;
  cin >> s >> n;
  for (int i = 0 ; i < s.size() ; ++ i)
    s[i] = tolower(s[i]);
  for (int i = 0 ; i < s.size() ; ++ i)

    if (islower(s[i]) && s[i] < 'a' + n)
      putchar(toupper(s[i]));
    else putchar(s[i]);
}

int main()
{
 // freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
  //init();
  //int _;cin>>_;while(_--)
  //while(RD(n) , n)
    work();
  return 0;
}