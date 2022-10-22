#include <iostream>

using namespace std;

int main(){
    int n, s;
    cin >> n >> s;

    int sum = 0, m = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        sum += a;
        m = max(m, a);
    }

    if(sum - m <= s)cout << "YES";
    else cout << "NO";

}