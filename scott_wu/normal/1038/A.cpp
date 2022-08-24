#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int N, K;
    string s;
    cin >> N >> K >> s;
    int mm = 1e9;
    for (int i = 0; i < K; i++)
    {
        int c = 0;
        for (int j = 0; j < N; j++)
            if (s[j] == 'A' + i)
                c++;
        mm = min (mm, c);
    }
    cout << mm * K << "\n";
}