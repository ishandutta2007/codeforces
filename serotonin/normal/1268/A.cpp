#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

int a[sz];
char s[sz];

int main()
{
    int n,k;
    cin >> n >> k;
    scanf("%s", s);
    for(int i=0; i<n; i++) a[i]=s[i]-'0';

    bool yes=1;
    for(int i=k, j=0; i<n; i++, j++) {
        if(j==k) j=0;
        if(a[j]>a[i]) break;
        if(a[j]<a[i]) {
            yes=0;
            break;
        }
    }

    if(!yes) {
        for(int i=k-1; i>=0; i--) {
            if(a[i]==9) a[i]=0;
            else {
                a[i]++;
                break;
            }
        }
    }
    printf("%d\n", n);
    for(int i=0, j=0; i<n; i++, j++) {
        if(j==k) j=0;
        printf("%d", a[j]);
    }
}