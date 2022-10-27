#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b;
int get_lucky(int x) {
    vector<int> v;
    while(x) {
        if(x % 10 == 4 || x % 10 == 7)
            v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());

    int t = 0;
    for(int i=0;i<v.size();i++) {
        t = 10*t + v[i];
    }
    return t;
}

int main() {
    cin >> a >> b; a ++;
    while(get_lucky(a) != b) {
        a ++;
    }
    printf("%d\n", a);
}