#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

int main()
{
    ll u,v;
    cin >> u >> v;

    ll one = u;
    ll sum = v - u;

    if(!sum) {
        if(u) {
            puts("1");
            cout << u << endl;
        }
        else {
            puts("0");
        }
        return 0;
    }

    if(sum&1 || sum<0) {
        puts("-1");
        return 0;
    }

    sum>>=1;

    if(one&sum) {
        puts("3");
        printf("%lld %lld %lld\n", one, sum, sum);
    }
    else {
        puts("2");
        printf("%lld %lld\n", sum, sum|one);
    }
}