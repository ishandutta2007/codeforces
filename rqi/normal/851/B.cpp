#include <iostream>

using namespace std;

int main() {
     ios_base::sync_with_stdio(false);
    long long a1, a2, b1, b2, c1, c2;
    long long d1, d3;
    bool test = false;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    d1 = (b1 - a1) * (b1 - a1) + (b2 - a2) * (b2 - a2);
    d3 = (c1 - b1) * (c1 - b1) + (c2 - b2) * (c2 - b2);
    if(b2 - a2== c2 - b2  && b1 - a1 == c1 - b1){
        test = true;
    }
    if(d1 == d3 && (test == false)){
        cout << "YES";
    }
    else cout << "NO";
}