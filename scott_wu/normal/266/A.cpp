#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string str;
    
    cin >> N >> str;
    
    int ans = 0;
    for (int i = 0; i < N - 1; i++)
        if (str[i] == str[i+1])
            ans++;
    cout << ans << "\n";
    return 0;
}