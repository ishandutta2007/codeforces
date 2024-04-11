#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int d[30][sz];
char s[sz];

int main()
{
    scanf("%s", s);
    for(int i=0; i<30; i++) {
        for(int j=0; s[j]; j++) {
            int x=s[j]-'a';
            if(x==i) d[i][j+1]++;
            d[i][j+1]+=d[i][j];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l,r;
        scanf("%d %d", &l, &r);

        if(l==r) puts("Yes");
        else {
            int cnt=0;
            for(int i=0; i<30; i++) {
                int x=d[i][r]-d[i][l-1];
                if(x) cnt++;
            }
            if(cnt>2) puts("Yes");
            else if(cnt==1) puts("No");
            else {
                if(s[l-1]==s[r-1]) puts("No");
                else puts("Yes");
            }
        }
    }
}