#include <iostream>
#include <algorithm>
using namespace std;
int n, k, and12, or12, and13, or13, and23, or23, ask12, ask13, And, Or, b[10005];

int main()
{
    cin >> n >> k;
    cout << "and 1 2\n";
    fflush(stdin);
    cin >> and12;

    cout << "or 1 2\n";
    fflush(stdin);
    cin >> or12;

    cout << "and 1 3\n";
    fflush(stdin);
    cin >> and13;

    cout << "or 1 3\n";
    fflush(stdin);
    cin >> or13;

    cout << "and 2 3\n";
    fflush(stdin);
    cin >> and23;

    cout << "or 2 3\n";
    fflush(stdin);
    cin >> or23;

    ask12 = and12 ^ or12;
    ask13 = and13 ^ or13;

    b[1] = (or12 & (~ask12)) | (or13 & (~ask13));
    b[1] ^= ask12 & ask13 & (~or23);

    b[2] = (b[1] ^ or12) | and12;
    b[3] = (b[1] ^ or13) | and13;
    for(int i=4; i<=n; ++i) {
        cout << "and 1 " << i << '\n';
        fflush(stdin);
        cin >> And;

        cout << "or 1 " << i << '\n';
        fflush(stdin);
        cin >> Or;

        b[i] = (b[1] ^ Or) | And;
    }
    sort(b+1, b+n+1);
    cout << "finish " << b[k];
}