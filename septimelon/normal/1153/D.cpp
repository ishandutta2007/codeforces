#include <iostream>

using namespace std;

int main()
{
    int val[300001];
    int roo[300001];
    int minof[300001];
    int n;
    int leafc = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        minof[i] = 0;
    }
    roo[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> roo[i];
    }
    for (int i = n; i > 1; i--) {
        if (minof[i] == 0) {
            minof[i] = 1;
            leafc++;
        }
        if (val[roo[i]] == 0) {
            minof[roo[i]]+=minof[i];
        }
        if (val[roo[i]] == 1) {
            if (minof[roo[i]] == 0)
                minof[roo[i]] = minof[i];
            else if (minof[roo[i]] > minof[i])
                minof[roo[i]] = minof[i];
        }
    }
    cout << leafc+1-minof[1] << endl;
    return 0;
}