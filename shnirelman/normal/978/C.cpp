#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<long long> s(n + 1);
    s[0] = 0;
    for(int i = 0; i < n; i++)
        s[i+1] = s[i] + a[i];

    for(int i = 0; i < m; i++){
        long long b;
        cin >> b;

        int l = 0, r = n;
        while(r - l > 0){
            int m = (r + l) / 2;
            if(s[m] < b)l = m + 1;
            else r = m;
        }

        cout << l << ' ' << b - s[l - 1] << endl;
    }
}