#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    int m = 0, s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < a[m])m = i;
        s += a[i];
    }

    if(s - a[m] != a[m] && n > 1)cout << 1 << endl << (m + 1);
    else cout << -1;
}