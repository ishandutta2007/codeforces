#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

struct chel
{
  int n;
  int score;
};

bool _less(chel a, chel b)
{
  if (a.score == b.score)
    return a.n < b.n;
  return a.score > b.score;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, t1, t2, k;
    int c, b;
    chel a[10000];
    cin >> n >> t1 >> t2 >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> c >> b;
      a[i].n = i + 1;
      a[i].score = max(t1 * c * (100 - k) + b * t2 * 100, t1 * b * (100 - k) + c * t2 * 100);
    }
    sort(a, a + n, _less);
    for (int i = 0; i < n; i++)
    {
      printf("%d ", a[i].n);
      cout << a[i].score / 100;
      cout << ".";
      c = a[i].score % 100;
      if (c < 10)
        cout << "0";
      cout << c;
      printf("\n");
    }
    return 0;
}