#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<int> b(12);
    b[0] = 31;
    b[1] = 28;
    b[2] = 31;
    b[3] = 30;
    b[4] = 31;
    b[5] = 30;
    b[6] = 31;
    b[7] = 31;
    b[8] = 30;
    b[9] = 31;
    b[10] = 30;
    b[11] = 31;

    int cnt29 = 0;
    for(int i = 0; i < n; i++)if(a[i] == 29){
        cnt29++;
        a[i] = 28;
    }

    if(cnt29 > 1){
        cout << "NO";
        return 0;
    }

    for(int i = 0; i < 12; i++){
        bool flag = false;
        for(int j = 0; j < n; j++)
            if(a[j] != b[(i + j) % 12])flag = true;

        if(!flag){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}