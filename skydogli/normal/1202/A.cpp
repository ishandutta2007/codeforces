#include<bits/stdc++.h>
using namespace std;
int T, k, ans;
#define MN 100005
char a[MN], b[MN];
int main(){
    scanf("%d", &T);
    while ( T-- ){
        scanf("%s %s", a, b);
        int len1 = strlen(a), len2 = strlen(b);
        for (int i=len2-1;i>=0;--i ) if (b[i]=='1') {k = i;break;}
        for (int i=len1-(len2-k);i>=0;--i ) if (a[i] == '1') { printf("%d\n", len1 - i - (len2 - k - 1) - 1); break ; }
    }
    return 0;
}