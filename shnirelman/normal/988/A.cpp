#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<bool> b(101, false);
    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!b[a[i]])cnt++;
        b[a[i]] = true;
    }
    
    if(cnt < k)cout << "NO";
    else {
        cout << "YES" << endl;
        for(int i = 0; i < n && k > 0; i++)
            if(b[a[i]]){
                k--;
                cout << i + 1 << ' ';
                b[a[i]] = false;
            }
    }
    
}