#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        if(n&1) {
            if(k&1) {
                if(n>=k*k) puts("YES");
                else puts("NO");
            }
            else puts("NO");
        }
        else {
            if(k&1) puts("NO");
            else {
                if(n>=k*k) puts("YES");
                else puts("NO");
            }
        }
    }
}