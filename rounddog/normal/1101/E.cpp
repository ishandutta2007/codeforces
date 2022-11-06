#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
int n,a,b,c,d;
char s[1];

int main(){
    cin >> n;
    while (n--){
        scanf("%s%d%d",s,&c,&d);
        if (c>d) swap(c,d);
        if (s[0]=='+') a=max(a,c),b=max(b,d);
        else if (c>=a&&d>=b) puts("YES"); else puts("NO");
    }
}