#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n , m, a[N];
int id[N];
void work() {
  scanf("%d" , &n);
  memset(id , -1 , sizeof(id));
  for (int i = 0 ; i < n ; ++ i) {
    scanf("%d" , &a[i]);
  }  
  vector<int> res;


  while (true) {
    memset(id , -1 , sizeof(id));
    for (int i = 0 ; i < n ; ++ i) {
      id[a[i]] = i;
    }
    int mex = 0;
    while (id[mex] != -1) {
      ++ mex;
    }
    if (mex < n) {
      a[mex] = mex;
      res.emplace_back(mex);
    } else {
      bool f = 0;
      for (int i = 0 ; i < n ; ++ i) {
        if (a[i] != i) {
          a[i] = mex;
          res.emplace_back(i);
          f = 1;
          break;
        }
      }
      if (!f) {
        break;
      }
    }
  }

  printf("%u\n" , res.size());
  for (int i = 0 ; i < res.size() ; ++ i) {
    printf("%d%c" , res[i] + 1 , " \n"[i + 1 == res.size()]);
  }
}

int main() {
  int T;
  scanf("%d" , &T);
  while (T --) {
    work();
  }
}