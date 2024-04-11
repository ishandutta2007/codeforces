#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int mna, mxa, mnb, mxb, mnc, mxc;
    cin >> mna >> mxa >> mnb >> mxb >> mnc >> mxc;
    int a = min(mxa, n - mnb - mnc), b = mnb, c = mnc;
    int sum = a + b + c;
    while(sum < n and a < mxa){
    	++a;
    	++sum;
    }
    while(sum < n and b < mxb){
    	++b;
    	++sum;
    }
    while(sum < n and c < mxc){
    	++c;
    	++sum;
    }
    cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}