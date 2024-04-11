#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n, k, s;
    cin >> n >> k >> s;

    if((long double)(s) / k > n -1 || (long double)(s) / k < 1){
        cout << "NO";
        return 0;
    }

    long long a = s / k + 1;
    int cnt1 = 0, cnt2 = 0;
    for(; ; cnt1++){
        if(cnt1 * a + (k - cnt1) * (a - 1) == s){
            cnt2 = k - cnt1;
            break;
        }
    }
    
    cout << "YES" << endl;

    bool b = true;
    int l = 1;
    for(int i = 0; i < cnt1; i++){
        if(b)l += a;
        else l -= a;
        b = !b;
        cout << l << ' ';
    }
    for(int i = 0; i < cnt2; i++){
        if(b)l += a - 1;
        else l -= a - 1;
        b = !b;
        cout << l << ' ';
    }
}