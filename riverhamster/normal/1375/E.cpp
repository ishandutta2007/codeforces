#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1005;
pair<int, int> p[N];
int a[N];
int pos[N];
int ra[N * N], rb[N * N], rc = 0;

int main(){
//  freopen("cf1375e.in", "r", stdin);
//  freopen("cf1375e.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &p[i].first), p[i].second = i;
  sort(p + 1, p + 1 + n);
  for(int i=1; i<=n; i++)
    a[p[i].second] = i, pos[i] = p[i].second;
  for(int i=n; i>=1; i--){
    int v = a[i];
    for(int j=v+1; j<=i; j++){
      int nowv = a[i];
      swap(a[i], a[pos[j]]);
      ++rc; ra[rc] = pos[j]; rb[rc] = i;
      swap(pos[nowv], pos[j]);
    }
  }
  printf("%d\n", rc);
  for(int i=1; i<=rc; i++)
    if(ra[i] > rb[i]) printf("%d %d\n", rb[i], ra[i]);
    else printf("%d %d\n", ra[i], rb[i]);
  return 0;
}