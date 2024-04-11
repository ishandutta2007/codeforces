#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n;
map<string , string> h;
void work() {
    scanf("%d",&n);
    for (int i = 0 ; i < n ; ++ i) {
        string a , b;
        cin >> a >> b;
        if (!h.count(a))
            h[a] = a;
        h[b] = h[a] , h.erase(a);
    }
    cout << h.size() << endl;
    for (auto& it : h) {
        cout << it.second << ' ';
        cout << it.first << endl;
    }
}

int main() {
    work();
    return 0;
}