#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;
int a[110], n, cur;

int main(){
   scanf("%d", &n);
   for(int i = 1; i <= n; i ++) scanf("%d", a+i);
   cur = 1;
   for(int i = 1; i <= n; i ++){
      if(a[i] == cur) { v.push_back(i+2000); cur++; }
   }
   printf("%d\n", v.size());
   for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]); puts("");
}