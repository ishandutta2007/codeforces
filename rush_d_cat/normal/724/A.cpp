                            
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int n;
map <string, int> mp;
int main()
{
    mp["monday"] = 1;
    mp["tuesday"] = 2;
    mp["wednesday"] = 3;
    mp["thursday"] = 4;
    mp["friday"] = 5;
    mp["saturday"] = 6;
    mp["sunday"] = 7;
    scanf("%d" ,&n);
    string a, b;
    cin >> a >> b;
    int x = (mp[b] - mp[a] + 7) % 7;
    if(x == 0 || x == 2 || x == 3) cout << "YES";
    else cout << "NO";
}