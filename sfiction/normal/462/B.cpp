/*
ID: Sfiction
OJ: CF
PROB: 462B
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int chr[26];

int main(){
    int n,k;
    char c;

    scanf("%d%d",&n,&k);
    while ((c=getchar())!=EOF)
        if ('A'<=c && c<='Z')
            ++chr[c-'A'];

    sort(chr,chr+26);
    long long ans=0;
    for (int i=25;i>=0 && k>=chr[i];--i){
        ans+=chr[i]*(long long)chr[i];
        k-=chr[i];
    }
    ans+=k*(long long)k;
    printf("%I64d",ans);
    return 0;
}