#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    
    vector<bool> b(10);
    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        b[c] = true;
    }
    
    for(int i = 0; i < n; i++)if(b[a[i]])cout << a[i] << ' ';
}