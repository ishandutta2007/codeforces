#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin >> t;
    string a = "Ashishgup", b = "FastestFinger";
    while(t--){
        int n;
        cin >> n;
        int m = 1;
        while(n % 2 == 0) n /= 2, m *= 2;
        int ok = 1;
        for(int j = 2; j * j <= n; j++)
            if(n % j == 0) ok = 0;
        cout << ((n == 1 && m != 2) || (n != 1 && m == 2 && ok) ? b : a)<<endl;

    }
}