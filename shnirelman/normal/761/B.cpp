#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, l;
    cin >> n >> l;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];

    int ind = 0;
    for(int i = 0; i < l; i++){
        if(i > a[n - 1])ind = 0;
        else if(a[ind] < i)ind++;

        bool flag = false;
        for(int j = 0; j < n && !flag; j++){
            if(a[(ind + j) % n] >= i){
                if(a[(ind + j) % n] - i != b[j])flag = true;
            }
            else if(l - i + a[(ind + j) % n] != b[j])flag = true;
        }

        if(!flag){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}