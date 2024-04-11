#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[102];
    int al[102], ah[102];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        al[i] = (a[i] & ((1 << 15) - 1));
        ah[i] = a[i] >> 15;
    }
    int c[100000] {0};
    for(int i = 0; i < (1 << 15); i++){
        for(int j = 0; j < 15; j++) if(i & (1 << j)) c[i]++;
    }
    map<vector<int>, int> mp;
    for(int i = 0; i < (1 << 15); i++){
        int les = 20;
        vector<int> v(n);
        for(int j = 0; j < n; j++){
            v[j] = c[al[j] ^ i];
            les = min(les, v[j]);
        }
        for(int j = 0; j < n; j++) v[j] -= les;
        mp[v] = i + 1;
    }
    for(int i = 0; i < (1 << 15); i++){
        int lar = 0;
        vector<int> v(n);
        for(int j = 0; j < n; j++){
            v[j] = c[ah[j] ^ i];
            lar = max(lar, v[j]);
        }
        for(int j = 0; j < n; j++) v[j] = lar - v[j];
        if(mp[v]){
            cout << (i << 15) + mp[v] - 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}