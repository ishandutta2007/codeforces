#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int numA;
    for (int i=0; i<300; i++)
        cout << 'a';
    cout << endl;
    cin >> numA;
    if (numA == 0)
        return 0;
    numA = 300 - numA;

    int numB;
    for (int i=0; i<300; i++)
        cout << 'b';
    cout << endl;
    cin >> numB;
    if (numB == 0)
        return 0;
    numB = 300 - numB;

    int cntA = 0, cntB = 0, x, init = numB;
    string ret(numA + numB, 'a');
    for (int i=0; i<numA+numB-1; i++) {
        ret[i] = 'b';
        cout << ret << endl;
        cin >> x;
        if (x == 0)
            return 0;
        else if (x > init)
            ret[i] = 'a';
        else
            init--;
        if (ret[i] == 'a') cntA++;
        else cntB++;
    }
    ret[numA+numB-1] = (cntA == numA ? 'b' : 'a');

    cout << ret << endl;

    return 0;
}