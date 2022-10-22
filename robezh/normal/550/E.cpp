#include <bits/stdc++.h>
using namespace std;

const string R = "->";
const int N = (int)1e5 + 50;

int n;
int a[N];
int in[N], out[N];

void print() {
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        if(i != 0) cout << R;
        for(int j = 0; j < in[i]; j++) cout << "(";
        cout << a[i];
        for(int j = 0; j < out[i]; j++) cout << ")";
    }
    exit(0);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    if(a[n-1] != 0) return cout << "NO" << endl, 0;
    if(n == 1 || a[n-2] == 1) print();

    int cnt = 0;
    for(int i = n - 2; i >= 0; ) {
        int l = i - 1;
        while(l >= 0 && a[l] == 1) {
            in[l]++;
            out[i]++;
            l--;
        }
        in[l+1]++;
        out[n-2]++;
        i = l;
        cnt++;
        if(cnt == 2) print();
    }
    cout << "NO" << endl;


}