 #include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int a, b, n, c;
int st (int q)
{
 int s=1, i=0;
 for (i=0; i<n; i++)
  s=s*q;
 return s;
}
int main ()
{
 scanf ("%d%d%d", &a, &b, &n);
 if (b==0)
 {
  printf ("0");
  return 0;
 }
 if (b!=0 && a==0)
 {
  printf ("No solution");
  return 0;
 }
 if (a*b<0 && n%2==0)
 {
  printf ("No solution");
  return 0;
 }
 if ((b/a)*a!=b)
 {
  printf ("No solution");
  return 0;
 }
 c=b/a;
 int q=1;
 while (st(q)<c)
  q++;
 if (st(q)==c)
 {
  printf ("%d", q);
  return 0;
 }
 q=-1;
 while (st(q)>c)
  q--;
 if (st(q)==c)
 {
  printf ("%d", q);
  return 0;
 }
 printf ("No solution");
return 0;
}