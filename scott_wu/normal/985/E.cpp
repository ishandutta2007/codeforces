#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int N, K, D;
int arr[500100];
vector <int> v;

int main()
{
    cin >> N >> K >> D;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);
    
    v.push_back(0);
    int vloc = 0;
    for (int i = 0; i < N; i++)
    {
        while (vloc < v.size() && arr[v[vloc]] + D < arr[i])
            vloc++;
        
        if (vloc < v.size() && v[vloc] + K - 1 <= i)
            v.push_back(i+1);
    }
    if (v[v.size() - 1] == N)
        cout << "YES\n";
    else
        cout << "NO\n";
}