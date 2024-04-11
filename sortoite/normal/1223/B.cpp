#include<bits/stdc++.h>
using namespace std;
char s[111], t[111], a[111], b[111];
int main(){
    int Q;cin>>Q;
    while(Q--) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        scanf("%s %s", s, t);
        for(int i=0; s[i]; i++) a[s[i]-'a']++;
        for(int i=0; t[i]; i++) b[t[i]-'a']++;
        int ok=0;
        for(int i=0; i<26; i++) if(a[i] && b[i]) ok=1;
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}