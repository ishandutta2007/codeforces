#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'x'){
            cnt++;
            if(cnt == 3){
                ans++;
                cnt--;
            }
        }
        else {
            cnt = 0;
        }
    }

    cout << ans;
}