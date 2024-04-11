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
        string a, b;
        cin >> a >> b;
        vector<int> ans;
        for(int i = n - 1; i >= 0; i--){
            if((n - i) % 2 == 1 && a[(n - i) / 2] == b[i]) ans.push_back(0);
            if((n - i) % 2 == 0 && a[n - (n - i) / 2] != b[i]) ans.push_back(0);
            ans.push_back(i);
        }
        cout << (int) ans.size() << " ";
        for(int i : ans) cout << i + 1 << " ";
        cout << endl;
    }
}