#include <iostream>
using namespace std;
int r, c;
char arr[1024][1024];
int main () {
    cin >> r >> c;
    for ( int i = 0 ; i < r ; i ++ ) {
        cin >> arr[i];
    }

    int ans = 0;
    for ( int i = 0 ; i < c ; i ++ ) {

        if ( ( i == 0 || arr[r-1][i-1] == '.' ) && arr[r-1][i] == 'B' ) {
            ans ++;
        }
    }
    cout << ans << "\n";

    return 0;
}