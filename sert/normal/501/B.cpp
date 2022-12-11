#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 512;

map <string, string> get_new, get_old;
map <string, string> :: iterator it;
string s1, s2;
int n;

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n;
    while (n --> 0) {
        cin >> s1 >> s2;
        if (get_old.find(s1) != get_old.end()) {
            s1 = get_old[s1];
            get_old[s2] = s1;
            get_new[s1] = s2;
        } else {
            get_old[s2] = s1;
            get_new[s1] = s2;
        }
    }

    cout << get_new.size() << "\n";

    for (it = get_new.begin(); it != get_new.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }

    
    //return 0;
}