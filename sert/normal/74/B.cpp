#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int N = 3e5 + 2;
#define fr(i, n) for(int i = 0; i < n; i++)

int n, z, k, np, st, len;
int pv[N];
int t0;
string s;
bool lft, rit;

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> z >> k;

    cin >> s >> s;
    if (s[0] == 'h') np = -1; else np = 1;
    cin >> s;

    if (z < k) lft = true;
    else rit = true;

    fr(i, s.length()){

        k = k + np;
        if (k == 1){lft = false; np = 1;}
        if (k == n){rit = false; np = -1;}

        if (!lft && !rit && s[i] == '0'){
            cout << "Controller " << i + 1;
            return 0;
        }

        if (s[i] == '1') lft = rit = true;
        if (k == 1) {lft = false;}
        if (k == n) {rit = false;}
    }

    if (!lft && !rit){
            cout << "Controller " << n;
            return 0;
    }

    cout << "Stowaway";

    return 0;
}