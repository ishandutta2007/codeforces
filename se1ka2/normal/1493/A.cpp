#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> ans;
        for(int i = n; i > k; i--) ans.push_back(i);
        for(int i = k - 1; i * 2 >= k; i--) ans.push_back(i);
        cout << (int)ans.size() << endl;
        for(int i : ans) cout << i << " ";
        cout << endl;
    }
}