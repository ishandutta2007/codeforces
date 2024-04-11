#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        bool yes=0;
        for(int i=0; i<a; i++) {
            int x;
            cin >> x;
            if(x==n) yes=1;
        }
        for(int i=0; i<b; i++) {
            int x;
            cin >> x;
        }
        if(yes) puts("YES");
        else puts("NO");
    }
}