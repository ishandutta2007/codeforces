#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200000];
    int b[200000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int cou = 0;
    int cur = b[n-1];
    int curind = n-1;
    if (cur != 0)
        curind--;
    while (b[curind] > 0 && b[curind] == b[curind+1]-1 && curind >= 0)
        curind--;
    if (b[curind+1] != 1)
        curind = n-1;
    if (curind == -1) {
        cout << "0" << endl;
        return 0;
    }
    curind++;
    // << curind << endl;
    int maxdif = 0;
    for (int i = 0; i < curind; i++) {
        if (b[i] != 0) {
            maxdif = max(maxdif,(i+2-b[i]+(n-curind)));
            //cout << b[i] << ": " << maxdif << endl;
        }
    }
    if (maxdif != 0) {
        for (int i = 0; i < n; i++) {
            if (b[i] != 0) {
                maxdif = max(maxdif,(i+2-b[i]));
            }
        }
        cout << n+maxdif << endl;
        return 0;
    }
    cout << curind << endl;
    return 0;
}