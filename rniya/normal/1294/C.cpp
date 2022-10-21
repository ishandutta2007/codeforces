#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        int a,b,c,ok0=0,ok1=0;
        for (a=2;a*a<=n;++a) if (n%a==0){
            n/=a; ok0=1; break;
        }
        if (!ok0){cout << "NO" << '\n'; continue;}
        for (b=a+1;b*b<=n;++b) if (n%b==0&&b!=n/b){
            c=n/b; ok1=1; break;
        }
        if (!ok1){cout << "NO" << '\n'; continue;}
        cout << "YES" << '\n';
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}