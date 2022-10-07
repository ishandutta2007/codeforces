#include <cstdio>

const int maxn =555;
int a[maxn],b[maxn];

int n;
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf ("%d%d", a+i, b+i);
int ans=0; for(int i =0; i<n;++i)for(int j =0;j<i;++j){
if(a[i]==b[j])++ans;
if(b[i]==a[j])++ans;
}
printf("%d\n", ans);
return 0;}