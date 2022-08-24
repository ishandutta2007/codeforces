#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int N;
    string str;
    
    cin >> N >> str;
    
    int sum = 0;
    bool good = true;
    for (int i = 0; i < N / 2; i++)
    {
        if (str[i] != '4' && str[i] != '7')
            good = false;
        sum += str[i];
    }
    for (int i = N/2; i < N; i++)
    {
        if (str[i] != '4' && str[i] != '7')
            good = false;
        sum -= str[i];
    }
    
    if (good && !sum)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}