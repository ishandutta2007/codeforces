#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;
typedef long long ll;
int n, num1[N], num2[N];
int s;

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> num1[i];
    sort(num1, num1+n);
    for(int i = 0; i < n; i++) num2[i] = num1[i];

    num2[n/2] = s;
    for(int i = 0; i < n/2; i++) if(num2[i] > s) num2[i] = s;
    for(int i = n/2 + 1; i < n; i++) if(num2[i] < s) num2[i] = s;


    //for(int i = 0; i < n; i++) cout << num2[i] << endl;
    ll res = 0;
    for(int i = 0; i < n; i++){
        int cur = num2[i] - num1[i];
        if(cur < 0) cur = -cur;
        res += cur;
    }
    cout << res << endl;
}