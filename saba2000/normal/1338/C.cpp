#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    ll t;
    cin >> t;
    for(ll TT = 1; TT <= t; TT++){
        ll n;
        cin >> n;
        ll T = (n-1)/3+1, B = 0;
        for(ll i = 0; i < 60; i+=2){
            if(T <= (1ll<< i)) {B = i; break;}
            else T -= (1ll << i);
        }
        ll X = T - 1, Y = 0, Z = 0;
        for(int i = 0; i < B; i+=2){
            int a  =0, b= 0;
            if(X & (1ll << i)) a = 1;
            if(X & (1ll << (i+1))) b = 1;
            if(a && !b) Y += (1ll<<(i+1));
            if(!a && b) Y += (1ll<<i) + (1ll<<(i+1));
            if(a && b) Y +=(1ll<<i);

        }
        X += (1ll<<B); Y+=(1ll<<(B+1));
        Z = X^Y;
        if(n % 3 == 1) cout << X<<endl;
        else if(n % 3 == 2) cout<<Y<<endl;
        else cout<<Z<<endl;
    }
}
/*
1 2 3
4 8 12
5 10 15
6 11 13
7 9 14

1 + 4

1 3 4 2
0000 0000 0000
0001 0010 0011
0010 0011 0001
0011 0001 0010
0100 10
0101
0110

16 32 48
17 34 51
18 35 49
19 33 50
20 40 60
21 42 63
22 43 61
23 41 62
24 44 52
25 46 55
26 47 53
27 45 54
28 36 56
29 38 59
30 39 57
31 37 58
*/