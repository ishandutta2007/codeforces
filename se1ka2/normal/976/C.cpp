#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;

int main()
{
    int n;
    cin >> n;
    PP p[300005];
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        p[i] = PP(P(l, -r), i);
    }
    sort(p, p + n);
    for(int i = 1; i < n; i++){
        if(-p[i].first.second <= -p[i - 1].first.second){
            cout << p[i].second + 1 << " " << p[i - 1].second + 1 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}