#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        int s[102];
        int d[2050] {0};
        for(int i = 0; i < n; i++){
            cin >> s[i];
            if(s[i] < 2050) d[s[i]]++;
        }
        for(int i = 0; i < 1025; i++){
            d[i * 2] += d[i] / 2;
        }
        if(d[2048]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}