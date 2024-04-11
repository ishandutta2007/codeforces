#include<bits/stdc++.h>
using namespace std;

struct crew{
    string name;
    string who;
    int id;
};

namespace ship {
    string c = "captain";
    string w = "woman";
    string ch = "child";
    string r = "rat";
    string m = "man";
    bool cmp(crew a, crew b) {
        if(a.who == b.who) return a.id < b.id;
        if(a.who == w && b.who == ch) return a.id < b.id;
        if(a.who == ch && b.who == w) return a.id < b.id;
        if(a.who == r) return 1;
        if(b.who == r) return 0;
        if(a.who == w || a.who == ch) return 1;
        if(b.who == w || b.who == ch) return 0;
        if(a.who == m) return 1;
        if(b.who == m) return 0;
        return 1;
    }
}

using namespace ship;

crew a[105];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) cin >> a[i].name >> a[i].who, a[i].id = i;
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i ++) cout << a[i].name << endl;
}