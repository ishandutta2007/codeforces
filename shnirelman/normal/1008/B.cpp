#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if(a[i] < b[i])swap(a[i], b[i]);
    }

    int last = 1000000013;
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(a[i] <= last)last = a[i];
        else if(b[i] <= last)last = b[i];
        else ans = false;
    }

    cout << (ans ? "YES" : "NO");
}