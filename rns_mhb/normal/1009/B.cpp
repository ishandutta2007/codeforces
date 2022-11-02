#include <bits/stdc++.h>

using namespace std;



inline char nc(){

  static char buf[100000],*p1=buf,*p2=buf;

  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }

  return *p1++;

}



inline int getint(){

  int x;

  char c=nc(),b=1;

  if(c == -1)

    return 0;

  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;

  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;

  return x;

}



#define pb push_back

#define x first

#define y second



template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 1e9;

const ll linf = 1e18;

const int mod = 1e9 + 7;

const double eps = 1e-7;



#define N 100005



int n, cnt;

char s[N], t[N];

char stk[N];



int main() {

    gets(s);

    n = strlen(s);

    int ones = 0;

    for (int i = 0; i < n; i ++) {

        if (s[i] != '1') stk[cnt++] = s[i];

        else ones ++;

    }

    int ps = 0;

    while (ps < cnt && stk[ps] != '2') ps ++; ps --;

    for (int i = 0; i <= ps; i ++) t[i] = stk[i];

    for (int i = ps + 1; i <= ps + ones; i ++) t[i] = '1';

    for (int i = ps + ones + 1; i < ones + cnt; i ++) t[i] = stk[i-ones];

    puts(t);

    return 0;

}