#include<bits/stdc++.h>
using namespace std;

int k, a[10], s;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tests;
    cin >>tests;
    while (tests--){
        cin >>k;
        s = 0;
        for (int i = 1; i <= 7; ++i){
            cin >>a[i];
            s += a[i];
        }
        k--;
        int ans = (k / s) * 7;
        k %= s;
        k++;
        int mn = 1e9;
        if (k == 0)mn = 0;
        for (int i = 1; i <= 7; ++i){
            int t = 0, ss = 0;
            int x = i;
            while (ss < k){
                ss += a[x];
                t++;
                x++;
                if (x == 8)x = 1;
            }
            mn = min(mn, t);
        }
        cout <<ans + mn<<'\n';
    }
}