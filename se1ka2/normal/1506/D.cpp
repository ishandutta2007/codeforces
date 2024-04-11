#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            mp[a]++;
        }
        int c = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            c = max(c, itr->second);
        }
        cout << max(n % 2, c * 2 - n) << endl;
    }
}