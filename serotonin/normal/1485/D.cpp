#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

int ans[] = {13439, 106064, 189279, 106064, 330095, 388944, 106064, 106064, 189279, 560720, 486464, 388944, 263744, 106064, 670095, 106064};
int l = 720720;
int a[sz][sz];

int main() {
   int n, m;
   cin >> n >> m;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         scanf("%d", &a[i][j]);
      }
   }
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         int x = i + j;
         if(x & 1) printf("%d ", l);
         else printf("%d ", ans[a[i][j] - 1]);
      }
      puts("");
   }
}