#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

double dval (int left, int right)
{
    if (right == 0)
        return 0;
    return (left + 0.0) / ((double) right);
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    cout << fixed << setprecision (7);
    cout << (1. + dval ((M - 1) * (N - 1), N * M - 1)) / ((double) N) << endl;
    //system ("Pause");
    return 0;
}