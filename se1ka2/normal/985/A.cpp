#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[102];
    for(int i = 0; i < n / 2; i++) cin >> a[i];
    sort(a, a + n / 2);
    int c[102];
    for(int i = 0; i < n / 2; i++) c[i] = i * 2 + 1;
    int s1 = 0;
    for(int i = 0; i < n / 2; i++) s1 += abs(a[i] - c[i]);
    for(int i = 0; i < n / 2; i++) c[i] = i * 2 + 2;
    int s2 = 0;
    for(int i = 0; i < n / 2; i++) s2 += abs(a[i] - c[i]);
    cout << min(s1, s2) << endl;
}