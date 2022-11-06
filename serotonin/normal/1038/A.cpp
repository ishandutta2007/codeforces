#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

int a[26];
char s[sz];

int main()
{
    int n,k,i;
    cin >> n >> k;
    memset(a, 0, sizeof a);
    cin >> s;
    for(i=0;i<n;i++) {
        a[s[i]-'A']++;
    }
    int x=n;
    for(i=0;i<k;i++) {
        x=min(x,a[i]);
    }
    printf("%d\n", x*k);
}