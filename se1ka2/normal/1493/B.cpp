#include <iostream>
using namespace std;

bool valid(int h, int m, int *a){
    int b[4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            if(a[i] == j){
                if(j == 0 || j == 1 || j == 8) b[3 - i] = j;
                else if(j == 2 || j == 5) b[3 - i] = 7 - j;
                else return false;
            }
        }
    }
    if(b[0] * 10 + b[1] < h && b[2] * 10 + b[3] < m) return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int h, m;
        cin >> h >> m;
        string s;
        cin >> s;
        int a[4];
        a[0] = s[0] - '0';
        a[1] = s[1] - '0';
        a[2] = s[3] - '0';
        a[3] = s[4] - '0';
        while(!valid(h, m, a)){
            a[3]++;
            if(a[3] == 10){
                a[3] = 0;
                a[2]++;
            }
            if(a[2] * 10 + a[3] == m){
                a[2] = 0;
                a[3] = 0;
                a[1]++;
            }
            if(a[1] == 10){
                a[1] = 0;
                a[0]++;
            }
            if(a[0] * 10 + a[1] == h){
                a[0] = 0;
                a[1] = 0;
            }
        }
        cout << a[0] << a[1] << ":" << a[2] << a[3] << endl;
    }
}