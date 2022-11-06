#include<bits/stdc++.h>
#define maxn 1000100

using namespace std;
char s[maxn];
int n,l,r,ans;
int main(){
    scanf("%s",s); n=strlen(s);
    l=0; while (l<n&&s[l]!='[') l++;
    l++; while (l<n&&s[l]!=':') l++;
    r=n-1; while (r>=0&&s[r]!=']') r--;
    r--; while (r>=0&&s[r]!=':') r--;
    if (l>=r) {puts("-1");return 0;}
    for (int i=l+1;i<r;i++) if (s[i]=='|') ans++;
    cout << ans+4 << endl;
    return 0;
}