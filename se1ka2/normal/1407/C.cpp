#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans[10005];
    int l = 0;
    for(int i = 1; i < n; i++){
        int d[2];
        cout << "? " << l + 1 << " " << i + 1 << endl;
        cin >> d[0];
        cout << "? " << i + 1 << " " << l + 1 << endl;
        cin >> d[1];
        if(d[0] > d[1]){
            ans[l] = d[0];
            l = i;
        }
        else ans[i] = d[1];
    }
    ans[l] = n;
    cout << "! ";
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}