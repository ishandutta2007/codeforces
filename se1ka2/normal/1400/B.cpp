#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int p, f;
        int c, d;
        int s, w;
        cin >> p >> f >> c >> d >> s >> w;
        if(s > w){
            swap(c, d);
            swap(s, w);
        }
        int ans = 0;
        for(int i = 0; i <= c; i++){
            if(i * s > p) break;
            int j = min(d, (p - s * i) / w);
            int k = min(c - i, f / s);
            int l = min(d - j, (f - s * k) / w);
            ans = max(ans, i + j + k + l);
        }
        cout << ans << endl;
    }
}