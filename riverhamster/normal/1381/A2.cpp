#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
  char ch; x = 0;
  int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 100005;
char a[N], b[N];

int main(){
//  File("a");
  int T;
  gi(T);
  while(T--){
    int n;
    gi(n);
    int flip = 0, bd[2];
    bd[0] = 1; bd[1] = n;
    scanf("%s%s", a + 1, b + 1);
    for(int i=1; i<=n; i++) a[i] -= '0', b[i] -= '0';
    static int op[N * 2];
    int oc = 0;
    for(int i=n; i>1; i--){
      int x = a[bd[flip ^ 1]] ^ flip, y = b[i];
      if(x == y){
        if(flip ^ 1) --bd[flip ^ 1];
        else ++bd[flip ^ 1];
        continue;
      }
      if((a[bd[flip]] ^ flip) == y) op[++oc] = 1;
      op[++oc] = i;
      flip ^= 1;
      if(flip ^ 1) --bd[flip ^ 1];
      else ++bd[flip ^ 1];
    }
    if((a[bd[1]] ^ flip) != b[1]) op[++oc] = 1;
    printf("%d ", oc);
    for(int i=1; i<=oc; i++) printf("%d ", op[i]);
    puts("");
  }
  return 0;
}