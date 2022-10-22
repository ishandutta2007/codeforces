#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200002], b[200002], c[200002];;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        c[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        int s = 0;
        for(; j <= c[b[i]]; j++){
            s++;
        }
        cout << s << " ";
    }
    cout << endl;
}