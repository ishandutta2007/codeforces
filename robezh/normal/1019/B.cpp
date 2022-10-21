#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int ask(int t){
    int res;
    cout << "? " << t << endl;
    fflush(stdout);
    cin >> res;
    return res;
}

int answer(int t){
    cout << "! " << t << endl;
    fflush(stdout);
    return 0;
}

int main(){
    cin >> n;
    bool lar;
    a = ask(1), b = ask(n / 2 + 1);
    if(a == b) return answer(1);
    lar = b > a;
    int l = 2, r = n/2, mid;
    while(l <= r){
        mid = (l + r) / 2;
        int y = ask(mid+n/2), x = ask(mid);
        if(x == y) return answer(mid);
        bool ok = (y > x) ^ (!lar);
        if(ok) l = mid + 1;
        else r = mid - 1;
    }
    return answer(-1);


}