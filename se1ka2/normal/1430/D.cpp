#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]) v.push_back(i);
        }
        int m = v.size();
        int i = 0, j = 0;
        int ans = 0;
        bool b[200005];
        for(int i = 0; i < n; i++) b[i] = 0;
        while(i < n){
            ans++;
            while(j < m && v[j] < i) j++;
            if(j == m){
                while(i < n && b[i]) i++;
                b[i] = true;
                i++;
                while(i < n && b[i]) i++;
                b[i] = true;
                i++;
            }
            else{
                b[v[j]] = true;
                j++;
                while(b[i]) i++;
                int l = i;
                while(i < n && s[i] == s[l]){
                    b[i] = true;
                    i++;
                }
            }
        }
        cout << ans << endl;
    }
}