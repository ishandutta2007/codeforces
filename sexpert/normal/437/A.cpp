#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> great;
    string A, B, C, D;
    cin >> A >> B >> C >> D;
    int a = A.length() - 2, b = B.length() - 2, c = C.length() - 2, d = D.length() - 2;
    if(a >= 2*b && a >= 2*c && a >= 2*d)
        great.insert('A');
    if(b >= 2*a && b >= 2*c && b >= 2*d)
        great.insert('B');
    if(c >= 2*a && c >= 2*b && c >= 2*d)
        great.insert('C');
    if(d >= 2*a && d >= 2*b && d >= 2*c)
        great.insert('D');
    if(2*a <= b && 2*a <= c && 2*a <= d)
        great.insert('A');
    if(2*b <= a && 2*b <= c && 2*b <= d)
        great.insert('B');
    if(2*c <= a && 2*c <= b && 2*c <= d)
        great.insert('C');
    if(2*d <= a && 2*d <= b && 2*d <= c)
        great.insert('D');
    if(great.size() == 1)
        cout << *great.begin() << endl;
    else
        cout << "C\n";
}