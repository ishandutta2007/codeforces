#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i <= 900; i++){
        int cnt = 0;
        int sum = 0;
        bool flag = false;
        for(int j = 0; j < n; j++){
            sum += int(s[j]) - int('0');
            if(sum == i){
                cnt++;
                sum = 0;
            }
            else if(sum > i){
                flag = true;
                break;
            }
            //if(i < 10)cout << sum << int(s[i]) <<< ' ';
        }
        //if(i < 10)cout << i << ' ' << cnt << ' ' << sum << flag << endl;
        if(!flag && cnt > 1 && sum == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}