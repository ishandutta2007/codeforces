#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1e5 + 2;
#define fr(i, n) for(int i = 0; i < n; i++)

string s;
int a;
int ai;


int main()
{
    //freopen("a.in", "r", stdin);
    cin >> a;
    a = 0;
    cin >> s;
    fr(i, s.length()){
        if (s[i] == 'A') a++;
        if (s[i] == 'I') ai++;
    }
    if (ai > 1){
        cout << 0;
        return 0;
    }

    if (ai == 1)
        cout << 1;
    else
        cout << a;

    return 0;
}