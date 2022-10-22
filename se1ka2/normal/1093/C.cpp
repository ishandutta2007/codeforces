#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll b[100005], a[200005];
    for(int i = 0; i < n / 2; i++) cin >> b[i];
    a[0] = 0, a[n - 1] = b[0];
    for(int i = 1; i < n / 2; i++){
        if(b[i] >= b[i - 1]){
            a[n - i - 1] = a[n - i];
            a[i] = b[i] - a[n - i];
        }
        else{
            a[i] = a[i - 1];
            a[n - i - 1] = b[i] - a[i - 1];
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}