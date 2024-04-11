#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, string> P;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if(k > m * n * 4 - m * 2 - n * 2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(n == 1){
        if(k <= m - 1){
            cout << 1 << endl;
            cout << k << " R" << endl;
        }
        else{
            cout << 2 << endl;
            cout << m - 1 << " R" << endl;
            cout << k - (m - 1) << " L" << endl;
        }
        return 0;
    }
    vector<P> v;
    if(k <= n - 1){
        v.push_back(P(k, "D"));
    }
    else if(k <= n * 2 - 2){
        v.push_back(P(n - 1, "D"));
        v.push_back(P(k - (n - 1), "U"));
    }
    else{
        v.push_back(P(n - 1, "D"));
        v.push_back(P(n - 1, "U"));
        k -= n * 2 - 2;
        int r = min(m - 1, k / ((n - 1) * 4 + 1));
        for(int i = 0; i < r; i++){
            v.push_back(P(n - 1, "RDL"));
            v.push_back(P(1, "R"));
            v.push_back(P(n - 1, "U"));
        }
        k -= ((n - 1) * 4 + 1) * r;
        if(r < m - 1){
            int l = min(n - 1, k / 3);
            if(l > 0) v.push_back(P(l, "RDL"));
            if(l < n - 1){
                k %= 3;
                if(k == 1) v.push_back(P(1, "R"));
                if(k == 2) v.push_back(P(1, "RD"));
            }
            else{
                k -= l * 3;
                if(k > 0){
                    v.push_back(P(1, "R"));
                }
                k--;
                if(k > 0) v.push_back(P(k, "U"));
            }
        }
        else{
            if(k > 0) v.push_back(P(k, "L"));
        }
    }
    cout << (int)v.size() << endl;
    for(P p : v){
        cout << p.first << " " << p.second << endl;
    }
}