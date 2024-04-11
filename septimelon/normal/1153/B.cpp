#include <iostream>

using namespace std;

int main()
{
    int he[101][101];
    int n, m, h;
    int a[101], b[101];
    int is[101][101];
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> is[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (is[i][j] == 0) {
                he[i][j] = 0;
            }
            else {
                if (a[j] > b[i])
                    he[i][j] = b[i];
                else
                    he[i][j] = a[j];
            }
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << he[i][j] << " ";
        cout << endl;
    }
    return 0;
}