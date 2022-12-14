#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1010
int f[N];

int main(){
    int n, x;
    //freopen("1.in", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; i++)scanf("%d", &x), f[x]++;
    for(int i=1; i<1000; i++)if(f[i]){
        if(f[i+1] && f[i+2]){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}