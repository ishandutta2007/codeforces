#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    if(m < n - 1){
        cout << "Impossible" << endl;
        return 0;
    }
    vector<P> v;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(gcd(i, j) == 1){
                v.push_back(P(i, j));
                m--;
            }
            if(m == 0) break;
        }
        if(m == 0) break;
    }
    if(m > 0){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for(P p : v) cout << p.first << " " << p.second << endl;
}