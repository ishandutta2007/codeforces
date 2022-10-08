#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const string t = "CODEFORCES";

int main () {
    string s;
    cin >> s;
    bool F = 0;
    if ((int) s.length() > (int) t.length()) {
        for (int i = 0; i <= (int) t.length(); i ++) 
            if (s.substr(0,(int) t.length()-i) == t.substr(0,(int) t.length()-i) && s.substr((int)s.length()-i) == t.substr((int)t.length()-i)) F = 1;
    }
    puts (F?"YES":"NO");
    return 0; 
}