#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

vector<int> v[200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        int b[30]{0};
        for(int i = 0; i < n; i++){
            if(b[s[i] - 'a'] <= 1){
                ans++;
                b[s[i] - 'a']++;
            }
        }
        cout << ans / 2 << endl;
    }
}