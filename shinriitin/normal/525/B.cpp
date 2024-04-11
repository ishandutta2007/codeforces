#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=200010;

char A[MAXN];

int n,m,cnt[MAXN];

int main(){
    scanf("%s",A+1);
    n=strlen(A+1);
    scanf("%d",&m);
    for(int i=1,x;i<=m;++i){
        scanf("%d",&x);
        ++cnt[x]; 
    }
    for(int i=1,j=(n>>1);i<=j;++i){
        cnt[i]+=cnt[i-1];
        if(cnt[i]&1)swap(A[i],A[n-i+1]);
    }
    puts(A+1);
    return 0;
}