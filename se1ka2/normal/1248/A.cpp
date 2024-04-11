#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int p[100002];
        ll op = 0, ep = 0;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            if(p[i] % 2 == 0) ep++;
            else op++;
        }
        int m;
        cin >> m;
        int q[100002];
        ll oq = 0, eq = 0;
        for(int i = 0; i < m; i++){
            cin >> q[i];
            if(q[i] % 2 == 0) eq++;
            else oq++;
        }
        cout << op * oq + ep * eq << endl;
    }
}