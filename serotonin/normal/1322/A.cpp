#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

int d[sz];
char s[sz];

int main()
{
    int n;
    cin >> n;
    scanf("%s", s);

    int ans=0, tot=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='(') tot++;
        else tot--;
        d[i]=tot;
    }

    for(int i=0; i<n; i++) {
        if(d[i]<0) {
            for(int j=i; j<n; j++) {
                ans++;
                i=j;
                if(!d[j]) break;
            }
        }
    }

    if(tot) puts("-1");
    else cout << ans;
}