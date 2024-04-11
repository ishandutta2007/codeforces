#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    int k = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> b;
    for(int i = 0; i < n; i++){
        k += (a[i] % 2 == 0) ? 1 : -1;
        if(k == 0 && i < n - 1){
            b.push_back(abs(a[i] - a[i + 1]));
        }
    }

    if(k != 0){
        cout << 0;
        return 0;
    }

    sort(b.begin(), b.end());

    for(int i = 0; i < b.size() && d >= 0; i++){
        if(b[i] <= d){
            d -= b[i];
            k++;
        }
        else break;
    }

    cout << k;

}