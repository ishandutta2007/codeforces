#include <iostream>
#include <string>
using namespace std;

const int INF = 1000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int h = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ')') h++;
            else h--;
            ans = max(ans, h);
        }
        cout << ans << endl;
    }
}