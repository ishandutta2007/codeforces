#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int u[100005];
    u[0] = 0;
    for(int i = 1; i <= n; i++){
        u[i] = u[i - 1] + (s[i - 1] - 'a') + 1;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        cout << u[r] - u[l] << endl;
    }
}