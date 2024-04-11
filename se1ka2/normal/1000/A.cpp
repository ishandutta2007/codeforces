#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        string b;
        cin >> b;
        if(mp[b]) mp[b]--;
        else ans++;
    }
    cout << ans << endl;
}