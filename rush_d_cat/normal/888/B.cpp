#include <iostream>
using namespace std;
char s[102]; 
int n,f[1002];
int main() {
    scanf("%d %s",&n,s+1);
    for (int i=1;i<=n;i++)
        f[s[i]]++;
    printf("%d\n", 2*min(f['U'],f['D'])+2*min(f['L'],f['R']));
}