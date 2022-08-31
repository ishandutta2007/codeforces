#include <iostream>

using namespace std;

int main()
{
    char ch[1100];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> ch[i];
    
    int cleft = 0;
    while (ch[cleft] == '.') cleft++;
    int cright = N - 1;
    while (ch[cright] == '.') cright--;
    
    if (ch[cleft] == 'L')
        cout << cright + 1 << " " << cleft << "\n";
    else if (ch[cright] == 'R')
        cout << cleft + 1 << " " << cright + 2 << "\n";
    else
    {
        while (ch[cleft] == 'R') cleft++;
        cout << cright + 1 << " " << cleft + 1 << "\n";
    }
    return 0;
}