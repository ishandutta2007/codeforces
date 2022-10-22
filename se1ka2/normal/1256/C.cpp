#include <iostream>
using namespace std;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    int c[1002];
    int sum = 0;
    for(int i = 0; i < m; i++){
        cin >> c[i];
        sum += c[i];
    }
    if(n - sum > (d - 1) * (m + 1)){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int r = (n - sum) % (m + 1);
    if(r == 0) r = m + 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < (n + m - sum) / (m + 1); j++) cout << 0 << " ";
        if(i != m) for(int j = 0; j < c[i]; j++) cout << i + 1 << " ";
    }
    for(int i = r; i < m + 1; i++){
        for(int j = 0; j < (n + m - sum) / (m + 1) - 1; j++) cout << 0 << " ";
        if(i != m) for(int j = 0; j < c[i]; j++) cout << i + 1 << " ";
    }
}