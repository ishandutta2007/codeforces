/*
STRIKE:

1.
2.

HEAL:

*/


#include <iostream>
#include <vector>
using namespace std;

int h1, a1, c1;
int h2, a2;

vector<int> vec;

int main() {
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;


    while (true) {

        int strike = 0;
        if ( (a1 >= h2) || (h1 > a2) ) {
            strike = 1;
        }
        vec.push_back(strike);

        if (strike) { // 0
            h2 -= a1;
            h1 -= a2;
        } else {
            h1 += c1;
            h1 -= a2;
        }

        if (h2 <= 0) {
            break;
        }

    }

    printf("%d\n", vec.size());

    for (int i = 0; i < vec.size(); i ++) {
        printf("%s\n", vec[i] ? ("STRIKE") : ("HEAL") );
    }


}