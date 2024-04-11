#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;
    int now = 0;
    int last = -1;
    int d[200004];
    char c[200004];
    for(int i = 0; i < n * 2 - 1; i++){
        if(s[i % n] != s[(i + 1) % n]){
            if(now == 0) last = i;
            now++;
        }
        else{
            for(int j = last; j <= (i + last) / 2; j++){
                d[j % n] = j - last;
                c[j % n] = s[last % n];
            }
            for(int j = i; j > (i + last) / 2; j--){
                d[j % n] = i - j;
                c[j % n] = s[i % n];
            }
            now = 0;
            last = i;
        }
    }
    if(now > n){
        cout << s << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(d[i] <= k) cout << c[i];
        else{
            if(k % 2 == 0) cout << s[i];
            else{
                if(s[i] == 'B') cout << 'W';
                else cout << 'B';
            }
        }
    }
    cout << endl;
}