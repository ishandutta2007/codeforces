#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string s[5203];
bool b[5203][5203];

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 4; j++){
            if(s[i][j] == 'F'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == 'E'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 0;
            }
            if(s[i][j] == 'D'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == 'C'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 0;
            }
            if(s[i][j] == 'B'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == 'A'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 0;
            }
            if(s[i][j] == '9'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == '8'){
                b[i][j * 4 + 0] = 1;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 0;
            }
            if(s[i][j] == '7'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == '6'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 0;
            }
            if(s[i][j] == '5'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == '4'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 1;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 0;
            }
            if(s[i][j] == '3'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == '2'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 1;
                b[i][j * 4 + 3] = 0;
            }
            if(s[i][j] == '1'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 1;
            }
            if(s[i][j] == '0'){
                b[i][j * 4 + 0] = 0;
                b[i][j * 4 + 1] = 0;
                b[i][j * 4 + 2] = 0;
                b[i][j * 4 + 3] = 0;
            }
        }
    }
    int g = 0;
    int l = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            l++;
            if(j == n - 1 || b[i][j] != b[i][j + 1]){
                g = gcd(g, l);
                l = 0;
            }
        }
    }
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            l++;
            if(i == n - 1 || b[i][j] != b[i + 1][j]){
                g = gcd(g, l);
                l = 0;
            }
        }
    }
    cout << g << endl;
}