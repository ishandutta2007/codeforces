#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

string s[10000];
char in[256];
int cnt;

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, i;
  scanf("%d", &n);
  cnt = 0;
  for(i = 0; i < n; i++){
    scanf("%s", in);
    if(!strcmp(in, "pwd")){
      cout<<"/";
      for(int j = 0; j < cnt; j++)
        cout<<s[j]<<"/";
      cout<<endl;
    }
    else{
      char *p1, *p2;
      scanf("%s", in);
      p1 = in;
      if(in[0] == '/'){
        cnt = 0;
        p1++;
      }
      while(*p1){
        p2 = p1;
        while(*p2 != '/' && *p2)
          p2++;
        if(*p1 == '.')
          cnt--;
        else
          s[cnt++] = string(p1, p2);
        if(*p2 == 0)
          break;
        p1 = p2+1;
      }
    }
  }
  return 0;
}