#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1005,inf=1e9;

char s[sz][sz];
int a[sz];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++) scanf("%s", s[i]);
    for(int i=0; i<m; i++) scanf("%d", &a[i]);

    int ans=0;
    for(int i=0; i<m; i++) {
        int c[5]={0};
        for(int j=0; j<n; j++) {
            c[s[j][i]-'A']++;
        }
        sort(c, c+5);
        ans+=c[4]*a[i];
    }
    cout << ans;
}