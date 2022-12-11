#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int l1, s1, r1, p1;
    int l2, s2, r2, p2;
    int l3, s3, r3, p3;
    int l4, s4, r4, p4;
    cin >> l1 >> s1 >> r1 >> p1;
    cin >> l2 >> s2 >> r2 >> p2;
    cin >> l3 >> s3 >> r3 >> p3;
    cin >> l4 >> s4 >> r4 >> p4;
    if((p1 && (l1 || s1 || r1 || s3 || l2 || r4))
     ||(p2 && (l2 || s2 || r2 || s4 || l3 || r1))
     ||(p3 && (l3 || s3 || r3 || s1 || l4 || r2))
     ||(p4 && (l4 || s4 || r4 || s2 || l1 || r3))){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}