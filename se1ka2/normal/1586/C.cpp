#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string s[1000005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<int> v;
    for(int j = 0; j < m - 1; j++){
        for(int i = 0; i < n - 1; i++){
            if(s[i][j + 1] == 'X' && s[i + 1][j] == 'X'){
                v.push_back(j);
                break;
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        auto itr = lower_bound(v.begin(), v.end(), l);
        if(itr == v.end()) cout << "YES" << endl;
        else{
            int j = *itr;
            if(j >= r - 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}