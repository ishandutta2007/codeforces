#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int ans, ans2;
        ans=a;
        if(c!=a) ans2=c;
        else ans2=d;
        printf("%d %d\n", ans, ans2);
    }
}