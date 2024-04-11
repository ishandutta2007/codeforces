#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        int n = s.size();
        int l = 0;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') l++;
            if(s[i] == '1'){
                v.push_back(l);
                l = 0;
            }
        }
        int k = v.size();
        int ans = 0;
        for(int i = 1; i < k; i++){
            ans += v[i];
        }
        cout << ans << endl;
    }
}