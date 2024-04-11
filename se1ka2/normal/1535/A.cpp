#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        P p[4];
        for(int i = 0; i < 4; i++){
            int a;
            cin >> a;
            p[i] = P(a, i);
        }
        sort(p, p + 4);
        if((p[0].second < 2 && p[1].second < 2) || (p[0].second >= 2 && p[1].second >= 2)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}