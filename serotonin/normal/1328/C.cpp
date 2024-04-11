#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e4+5;

char s[sz];

int a[sz], b[sz];

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        int n,k;
        scanf("%d %s", &n, s);
        for(int i=0; i<n; i++) {
            if(s[i]=='2') a[i]=1, b[i]=1;
            else if(s[i]=='0') a[i]=0, b[i]=0;
            else {
                if(s[i]=='1') a[i]=1, b[i]=0;
                for(int j=i+1; j<n; j++) {
                    a[j]=0; b[j]=s[j]-'0';
                }
                break;
            }
        }
        for(int i=0; i<n; i++) printf("%d", a[i]);
        puts("");
        for(int i=0; i<n; i++) printf("%d", b[i]);
        puts("");
    }
}