#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int c = 0;
        int p[102];
        for(int i = 0; i < n * m; i++){
            cin >> p[i];
            if(p[i] < 0) c++;
            p[i] = abs(p[i]);
        }
        sort(p, p + n * m, greater<int>());
        int s = 0;
        for(int i = 0; i < n * m; i++) s += p[i];
        if(c % 2) s -= p[n * m - 1] * 2;
        cout << s << endl;
    }
}