#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m = {{"Tetrahedron", 4}, {"Cube", 6}, {"Octahedron", 8},
    {"Dodecahedron", 12}, {"Icosahedron", 20}};

int main() {
    int n, ret = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        ret += m[s];
    }
    cout << ret << endl;
    
    return 0;
}