#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,l,r,d;

int main(){
    cin >> q;
    while (q--){
        cin >> l >> r >> d;
        if (l>d) printf("%lld\n",d);
        else printf("%lld\n",(r/d+1)*d);
    }
    return 0;
}