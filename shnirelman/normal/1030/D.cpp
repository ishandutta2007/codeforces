#include <iostream>
#include <string>

using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;

    if((((n * m * 2) % k)) != 0){

        cout << "NO";
        return 0;

    }

    cout << "YES" << endl;

    long long n1 = n, m1 = m;

    for(int i = 2; i <= min(n, k); i++)
        while(n % i == 0 && k % i == 0){
            n /= i;
            k /= i;
        }

    if(m % k == 0){
        m /= k;
        if(m * 2 <= m1){
            cout << 0 << ' ' << 0 << endl;
            cout << 0 << ' ' << m * 2 << endl;
            cout << n << ' ' << 0 << endl;
        }
        else{
            cout << 0 << ' ' << 0 << endl;
            cout << 0 << ' ' << m << endl;
            cout << n * 2 << ' ' << 0 << endl;
        }
    }
    else{
        k /= 2;
        m /= k;

        cout << 0 << ' ' << 0 << endl;
        cout << 0 << ' ' << m << endl;
        cout << n << ' ' << 0 << endl;

    }

}