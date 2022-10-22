#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    int ind = 1;
    vector<bool> b(n + 2);
    /*
    for(int i = 0; i < n; i++){
        if(a[i] > n || b[a[i]]){
            a[i] = ind;
            b[ind] = true;
        }
        else b[a[i]] = true;

        while(b[ind])ind++;
    }
*/
    vector<bool> b1(n, false);
    for(int i = 0; i < n; i++)
        if(a[i] <= n && !b[a[i]]){
            b[a[i]] = true;
            b1[i] = true;
        }

    for(int i = 0; i < n; i++)
        if(!b1[i]){
            while(b[ind])ind++;
            b[ind] = true;
            a[i] = ind;
        }

    for(int i = 0; i < n; i++)cout << a[i] << ' ';
}