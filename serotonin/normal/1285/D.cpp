#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int fnc(int pos, vector <int> ara)
{
    if(pos<0) return 0;

    vector <int> one, two;

    for(int i=0; i<ara.size(); i++) {
        if(ara[i] & (1<<pos)) one.push_back(ara[i]);
        else two.push_back(ara[i]);
    }

    if(one.empty() || two.empty()) return fnc(pos-1, ara);

    int x = min(fnc(pos-1, one), fnc(pos-1, two));
    return (1<<pos)|x;
}

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    cout << fnc(30, a);
}