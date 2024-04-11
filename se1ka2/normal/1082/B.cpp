#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int g = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'G') g++;
    }
    int f = 0, l = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'G') f++;
        else{
            l = f;
            f = 0;
        }
        ans = max(ans, f + l + 1);
    }
    cout << min(ans, g) << endl;
}