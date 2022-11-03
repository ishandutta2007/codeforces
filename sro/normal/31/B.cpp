#include <stdio.h>
#include <string.h>
int n,p,i,l=1000000000;
char a[222];
int main() {
  gets(a); n=strlen(a); p=-2;
  for (i=0; i<n; i++) if (a[i]=='@') {
    if (i-p<l) l=i-p; p=i;
  }
  if (n+1-p<l) l=n+1-p;
  if (p==-2 || l<3) { puts("No solution"); return 0; }
  for (i=0; i<n; i++) {
    putchar(a[i]);
    if (i>0 && i!=n-1 && a[i-1]=='@' && i-1<p) putchar(',');
  }
  return 0;
}