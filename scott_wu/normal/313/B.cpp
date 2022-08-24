#include <iostream>
#include <string>

using namespace std;

int N, M;
string str;
int ps[100100];

int main()
{
    cin >> str >> M;
    N = str.length();
    
    ps[0] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        ps[i+1] = ps[i];
        if (str[i] == str[i+1])
            ps[i+1]++;
    }
    
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        
        cout << ps[y-1] - ps[x-1] << "\n";
    }
    return 0;
}