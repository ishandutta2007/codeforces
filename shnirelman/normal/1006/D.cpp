#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s, s1;
    cin >> s;
    cin >> s1;

    int ans = 0;

    int k = n / 2 + n % 2;

    for(int i = 0; i < k; i++){
        char a, b, c, d;
        a = s[i];
        c = s1[i];
        b = s[n - i - 1];
        d = s1[n - i - 1];

        if(a == d || b == c)swap(c, d);

        if(i == n - i - 1){
            if(a != c){
                //cout << a << ' ' << c << ' ' << ans << endl;
                ans++;
            }
        }
        else{
            if(a != c && b != d){
                if(a != b && c == d)ans++;
                else if(c != d)ans += 2;
            }
            else {
                if(a != c)ans++;
                if(b != d)ans++;
            }
        }
        /*if(!(a == b && c == d)){
            if(a != c)ans++;
            if(b != d)ans++;
        }*/

        //cout << i << ' ' << n - i - 1 << ' ' << ans << endl;
    }

    cout << ans;
}