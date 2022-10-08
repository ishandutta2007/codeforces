#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 110

int n, m;
string a[N];
int S = 0;

bool good(char a, char b, char c, char d) {
    set<char> A;
    A.insert(a);
    A.insert(b);
    A.insert(c);
    A.insert(d);
    if (A.find('f') == A.end()) return false;
    if (A.find('a') == A.end()) return false;
    if (A.find('c') == A.end()) return false;
    if (A.find('e') == A.end()) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n-1; i ++) 
        for (int j = 0; j < m-1; j ++) 
            if (good(a[i][j], a[i+1][j], a[i][j+1], a[i+1][j+1])) {
                S ++;
            }
    printf ("%d\n", S);
    return 0;
}