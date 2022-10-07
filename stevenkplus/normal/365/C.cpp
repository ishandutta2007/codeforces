#include <cstdio>
#include <algorithm>
using namespace std;
char str[10000];
int sums[10000];
int vals[16000000];
int a;

typedef long long ll;
int main() {
scanf("%d", &a);
scanf("%s", str);
for(int i = 0; str[i]; ++i) {
sums[i + 1]=sums[i]+str[i]-'0';
}
ll nx = 0;
int n0=0;
for(int i = 0; str[i]||str[i-1]; ++i) { 
for(int j = 0; j < i; ++j) {
int x = sums[i] - sums[j];
if(x)
vals[nx++]=x;
else ++n0;}
}
ll ans = 0;
sort(vals,vals+nx);
if(a==0) {
ans = (nx+n0)*(nx+n0)-nx*nx;
}else{
int l = 0; int r = nx - 1;
int rc = 1;
while (l < nx && r >= 0) {
while(r > 0 && vals[r-1]==vals[r]) {
--r;++rc;
}

int prod = vals[l]*vals[r];
if(prod>a){--r; rc=1;}
else if (prod==a) {
ans+=rc;++l;
}
else ++l;
}}
printf("%I64d\n", ans);
return 0;
}