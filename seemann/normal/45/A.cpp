#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#define ll long long int
#define FOR(a, b) for (int a = 0; s < b; a++)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

map <string, int> m;
map <int, string> c;
int main()
{
    m["January"] = 0;
    m["February"] = 1;
    m["March"] = 2;
    m["April"] = 3;
    m["May"] = 4;
    m["June"] = 5;
    m["July"] = 6;
    m["August"] = 7;
    m["September"] = 8;
    m["October"] = 9;
    m["November"] = 10;
    m["December"] = 11;
    c[0] = "January";
    c[1] = "February";
    c[2] = "March";
    c[3] = "April";
    c[4] = "May";
    c[5] = "June";
    c[6] = "July";
    c[7] = "August";
    c[8] = "September";
    c[9] = "October";
    c[10] = "November";
    c[11] = "December";
    string s;
    int k;
    cin >> s >> k;
    int x = (m[s] + k) % 12;
    cout << c[x];




    return 0;
}