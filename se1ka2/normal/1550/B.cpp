#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        if(b >= 0){
            cout << (a + b) * n << endl;
        }
        else{
            int c = 1;
            for(int i = 1; i < n; i++){
                if(s[i] != s[i - 1]) c++;
            }
            cout << a * n + b * ((c + 2) / 2) << endl;
        }
    }
}